#include "Exceptions/InvalidCommandException.hpp"

InvalidCommandException::InvalidCommandException(const string &message)
    : runtime_error(message) {}