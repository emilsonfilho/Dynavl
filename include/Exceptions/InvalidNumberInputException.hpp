#ifndef INVALID_NUMBER_INPUT_EXCEPTION_HPP
#define INVALID_NUMBER_INPUT_EXCEPTION_HPP

#include <stdexcept>
#include <string>

using std::exception;
using std::invalid_argument;
using std::stoi;
using std::string;

class InvalidNumberInputException : public invalid_argument {
public:
  /**
   * @brief Creates an invalid number of input exception
   *
   * @param message Message to be displayed
   */
  explicit InvalidNumberInputException(const string &message);
};

#endif
