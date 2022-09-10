#ifndef SERVICE_H
#define SERVICE_H

#include "languages.h"
#include "question.h"
#include "random_wrapper.h"
#include <cpr/cpr.h>
#include <cpr/response.h>
#include <string>

class Service {
public:
  Service();

  Question next_question();

  cpr::Response fetch_random_repo(Language::Type language);

  std::string fetch_random_file(cpr::Response &&repo);

  std::string get_random_code(std::string &&file);

private:
  std::string get_random_repo_name(cpr::Response &&r);
  std::string get_random_file_url(cpr::Response &&r);

private:
public:
  RandomWrapper random;
};

#endif // SERVICE_H
