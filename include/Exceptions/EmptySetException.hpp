#ifndef EMPTY_SET_EXCEPTION_HPP
#define EMPTY_SET_EXCEPTION_HPP

#include <stdexcept>

using std::runtime_error;
using std::string;

class EmptySetException : public runtime_error {
public:
  /**
   * @brief Creates an exception for an empty set
   *
   * @param message Message to be displayed
   */
  explicit EmptySetException(const string &message);
};

#endif
