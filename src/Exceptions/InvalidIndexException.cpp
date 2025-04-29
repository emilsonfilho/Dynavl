
#include "Exceptions/InvalidIndexException.hpp"

InvalidIndexException::InvalidIndexException(const string &message)
    : invalid_argument(message) {}