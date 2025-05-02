#ifndef INVALID_NUMBER_INPUT_EXCEPTION_HPP
#define INVALID_NUMBER_INPUT_EXCEPTION_HPP

#include <stdexcept>
#include <string>

using std::string;
using std::invalid_argument;
using std::stoi;
using std::exception;

class InvalidNumberInputException : public invalid_argument {
public:
  /**
   * @brief Creates an invalid argument exception
   *
   * @param message Message to be displayed
   */
  explicit InvalidNumberInputException(const string &message);
};

#endif
