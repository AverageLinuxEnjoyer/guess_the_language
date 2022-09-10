#include "../include/service.h"
#include "../include/base64.h"
#include <algorithm>
#include <cpr/response.h>
#include <fmt/core.h>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

Question Service::next_question() {

  Language::Type language = this->random.language();

  auto random_repo = this->fetch_random_repo(language);

  std::string random_file = this->fetch_random_file(std::move(random_repo));

  std::string code = this->get_random_code(std::move(random_file));

  auto possible = this->random.languages(3);
  possible.push_back(language);
  this->random.shuffle_vector(possible);

  unsigned int correct = 0;
  for (int i = 0; i < possible.size(); i++) {
    if (possible[i] == language)
      correct = i;
  }

  std::vector<std::string> answers(possible.size());
  std::transform(
      possible.begin(), possible.end(), answers.begin(),
      [](Language::Type &l) { return Language::get_display_string(l); });

  return Question{.text = code, .answers = answers, .correct = correct};
}

std::string Service::fetch_random_file(cpr::Response &&repo) {

  std::string file_url = this->get_random_file_url(std::move(repo));

  cpr::Response req1 = cpr::Get(cpr::Url{file_url});

  json file = json::parse(req1.text);

  // the base64 encoded file
  auto contents = file.at("content");

  return base64_decode(contents, true);
}

std::string Service::get_random_code(std::string &&file) {
  int size = file.size();

  auto begin = file.find("\n\n", size / 2);

  if (begin == std::string::npos) {
    return file.substr(0, 600);
  }

  std::string code = file.substr(begin, 600);

  return code;
}

std::string Service::get_random_file_url(cpr::Response &&r) {

  json resp = json::parse(r.text);

  auto all_files = resp.at("items");

  int rand_index = random.integer(0, all_files.size() - 1);

  auto parsed = all_files.at(rand_index).at("url");

  return parsed;
}

cpr::Response Service::fetch_random_repo(Language::Type language) {
  std::string repo_list_url = fmt::format(
      "api.github.com/search/repositories?q=language:{}&sort=stars&order=desc",
      Language::get_github_string(language));

  cpr::Response req1 = cpr::Get(cpr::Url{repo_list_url});

  if (req1.status_code != 200) {
    std::cout << "Data couldn't be received from github.\n";
    // todo: throw exception instead
  }

  std::string repo_name = this->get_random_repo_name(std::move(req1));

  std::string repo_url =
      fmt::format("api.github.com/search/code?q=%20+language:{}+repo:{}",
                  Language::get_github_string(language), repo_name);

  cpr::Response req2 = cpr::Get(cpr::Url{repo_url});

  return req2;
}

std::string Service::get_random_repo_name(cpr::Response &&r) {

  json resp = json::parse(r.text);

  // may throw, catch it!
  auto all_repos = resp.at("items");

  int rand_index = random.integer(0, all_repos.size() - 1);

  // may throw, catch it!
  auto parsed = all_repos.at(rand_index).at("full_name");

  return parsed;
}
