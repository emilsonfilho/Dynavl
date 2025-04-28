#include "Exceptions/EmptyRepositoryException.hpp"

EmptyRepositoryException::EmptyRepositoryException(const string &message)
    : runtime_error(message) {}