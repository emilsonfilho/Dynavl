#ifndef INVALID_COLUMN_EXCEPTION_HPP
#define INVALID_COLUMN_EXCEPTION_HPP

#include <stdexcept>

using std::runtime_error;
using std::string;

class InvalidCommandException : public runtime_error {
public:
  /**
   * @brief Creates an invalid command exception
   *
   * @param message Message to be displayed
   */
  explicit InvalidCommandException(const string &message);
};

#endif