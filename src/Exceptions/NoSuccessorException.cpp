#include "Exceptions/NoSuccessorException.hpp"

NoSuccessorException::NoSuccessorException(const string &message)
    : runtime_error(message) {}
