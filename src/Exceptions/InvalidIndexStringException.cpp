#include "Exceptions/InvalidIndexStringException.hpp"

InvalidIndexStringException::InvalidIndexStringException(const string &message)
    : invalid_argument(message) {}