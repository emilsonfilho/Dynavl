#ifndef NO_PREDECESSOR_EXCEPTION_HPP
#define NO_PREDECESSOR_EXCEPTION_HPP

#include <stdexcept>

using std::runtime_error;
using std::string;

class NoPredecessorException : public runtime_error {
public:
  /**
   * @brief Creates an exception for an empty set
   *
   * @param message Message to be displayed
   */
  explicit NoPredecessorException(const string &message);
};

#endif
