#include "Exceptions/NoPredecessorException.hpp"

NoPredecessorException::NoPredecessorException(const string &message)
    : runtime_error(message) {}
