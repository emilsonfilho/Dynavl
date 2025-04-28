#ifndef INVALID_INDEX_STRING_EXCEPTION_HPP
#define INVALID_INDEX_STRING_EXCEPTION_HPP

#include <stdexcept>

using std::string;
using std::invalid_argument;

class InvalidIndexStringException : public invalid_argument {
public:
  /**
   * @brief Creates an invalid argument exception
   *
   * @param message Message to be displayed
   */
  explicit InvalidIndexStringException(const string &message);
};

#endif