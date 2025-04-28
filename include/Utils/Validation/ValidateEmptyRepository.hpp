#ifndef VALIDATE_EMPTY_REPOSITORY
#define VALIDATE_EMPTY_REPOSITORY

#include "Exceptions/EmptyRepositoryException.hpp"
#include "Messages/EmptyRepositoryMessage.hpp"

void ValidateEmptyRepository(size_t repositorySize);

#endif