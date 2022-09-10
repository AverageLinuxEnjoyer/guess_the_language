#ifndef RANDOM_WRAPPER_H
#define RANDOM_WRAPPER_H

#include "languages.h"
#include <random>
#include <vector>

class RandomWrapper {
public:
  RandomWrapper();

  Language::Type language();
  std::vector<Language::Type> languages(int count);
  int integer(int low, int high);
  void shuffle_vector(std::vector<Language::Type> &vec);

private:
  std::random_device dev;
  std::mt19937 rng;
};

#endif // RANDOM_WRAPPER_H
