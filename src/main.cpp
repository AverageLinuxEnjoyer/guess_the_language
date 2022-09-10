
#include "../include/clear_console.h"
#include "../include/service.h"
#include <exception>
#include <iostream>

int main() {
  Service s;

  while (true) {
    Question question;
    try {
      question = s.next_question();
    } catch (std::exception &_) {
      continue;
    }
    std::cout << question.text << std::endl;

    for (int i = 0; i < question.answers.size(); i++) {
      std::cout << i + 1 << ")\t" << question.answers[i] << std::endl;
    }

    unsigned int input;
    do {
      std::cout << ">";
      try {
        std::cin >> input;
      } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
        continue;
      }

      if (input == question.correct + 1) {
        Clear();
        std::cout << "Correct!\nWait for the next question...\n";
        break;
      } else
        std::cout << "That's incorrect. Try again.\n";
    } while (true);
  }
  try {

  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }
}
