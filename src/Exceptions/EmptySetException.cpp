#include "Exceptions/EmptySetException.hpp"

EmptySetException::EmptySetException(const string &message)
    : runtime_error(message) {}
