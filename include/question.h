#ifndef QUESTION_H
#define QUESTION_H

#include <string>
#include <vector>

struct Question {
  std::string text;
  std::vector<std::string> answers;
  unsigned int correct;
};

#endif // QUESTION_H
