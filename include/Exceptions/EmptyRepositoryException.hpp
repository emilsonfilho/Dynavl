#ifndef EMPTY_REPOSITORY_EXCEPTION_HPP
#define EMPTY_REPOSITORY_EXCEPTION_HPP

#include <stdexcept>

using std::runtime_error;
using std::string;

class EmptyRepositoryException : public runtime_error {
public:
  /**
   * @brief Creates an exception for an empty repository
   *
   * @param message Message to be displayed
   */
  explicit EmptyRepositoryException(const string &message);
};

#endif