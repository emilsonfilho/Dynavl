#ifndef NO_SUCCESSOR_EXCEPTION_HPP
#define NO_SUCCESSOR_EXCEPTION_HPP

#include <stdexcept>

using std::runtime_error;
using std::string;

class NoSuccessorException : public runtime_error {
public:
  /**
   * @brief Creates an exception for an empty set
   *
   * @param message Message to be displayed
   */
  explicit NoSuccessorException(const string &message);
};

#endif
