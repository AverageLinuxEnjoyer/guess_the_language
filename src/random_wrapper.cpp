#include "../include/random_wrapper.h"
#include <algorithm>

RandomWrapper::RandomWrapper() : dev(), rng((dev())) {}

Language::Type RandomWrapper::language() {
  // where Language::COBOL must be the last enum value
  std::uniform_int_distribution<size_t> dis(0, Language::COBOL);
  return static_cast<Language::Type>(dis(this->rng));
}

std::vector<Language::Type> RandomWrapper::languages(int count) {
  std::vector<Language::Type> vec;
  vec.reserve(count);
  for (int i = 0; i < count; i++) {
    vec.push_back(this->language());
  }

  return vec;
}

int RandomWrapper::integer(int low, int high) {
  std::uniform_int_distribution<int> dis(low, high);
  return dis(this->rng);
}

void RandomWrapper::shuffle_vector(std::vector<Language::Type> &vec) {
  std::shuffle(vec.begin(), vec.end(), rng);
}
