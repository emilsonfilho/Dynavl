#include "Exceptions/InvalidArgumentException.hpp"

InvalidArgumentException::InvalidArgumentException(const string &message)
    : invalid_argument(message) {}