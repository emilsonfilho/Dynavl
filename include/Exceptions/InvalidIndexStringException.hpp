#ifndef INVALID_INDEX_STRING_EXCEPTION_HPP
#define INVALID_INDEX_STRING_EXCEPTION_HPP

#include <stdexcept>

using std::invalid_argument;
using std::string;

class InvalidIndexStringException : public invalid_argument {
public:
  /**
   * @brief Creates an invalid index string exception
   *
   * @param message Message to be displayed
   */
  explicit InvalidIndexStringException(const string &message);
};

#endif