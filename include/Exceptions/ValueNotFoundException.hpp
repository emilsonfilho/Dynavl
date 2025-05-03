#ifndef VALUE_NOT_FOUND_EXCEPTION_HPP
#define VALUE_NOT_FOUND_EXCEPTION_HPP

#include <stdexcept>

using std::runtime_error;
using std::string;

class ValueNotFoundException : public runtime_error {
public:
  /**
   * @brief Creates an exception for an empty set
   *
   * @param message Message to be displayed
   */
  explicit ValueNotFoundException(const string &message);
};

#endif
