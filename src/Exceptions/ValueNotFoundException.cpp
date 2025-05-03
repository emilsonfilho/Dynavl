#include "Exceptions/ValueNotFoundException.hpp"

ValueNotFoundException::ValueNotFoundException(const string &message)
    : runtime_error(message) {}
