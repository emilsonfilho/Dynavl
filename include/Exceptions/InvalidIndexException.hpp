
#ifndef INVALID_INDEX_EXCEPTION_HPP
#define INVALID_INDEX_EXCEPTION_HPP

#include <stdexcept>

using std::invalid_argument;
using std::string;

class InvalidIndexException : public invalid_argument {
public:
  /**
   * @brief Creates an invalid index exception
   *
   * @param message Message to be displayed
   */
  explicit InvalidIndexException(const string &message);
};

#endif