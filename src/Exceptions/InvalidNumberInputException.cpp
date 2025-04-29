#include "Exceptions/InvalidNumberInputException.hpp"

InvalidNumberInputException::InvalidNumberInputException(const string &message)
    : invalid_argument(message) {}