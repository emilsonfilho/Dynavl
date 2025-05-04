#ifndef INVALID_ARGUMENT_EXCEPTION_HPP
#define INVALID_ARGUMENT_EXCEPTION_HPP

#include <stdexcept>

using std::invalid_argument;
using std::string;

class InvalidArgumentException : public std::invalid_argument {
public:
  /**
   * @brief Creates an invalid argument exception
   *
   * @param message Message to be displayed
   */
  explicit InvalidArgumentException(const string &message);
};

#endif