#ifndef VALIDATE_EMPTY_REPOSITORY
#define VALIDATE_EMPTY_REPOSITORY

#include "Exceptions/EmptyRepositoryException.hpp"
#include "Messages/EmptyRepositoryMessage.hpp"

/**
 * @brief Validates whether a repository is empty.
 *
 * This function checks if the repository size is zero. If it is, it throws
 * an `EmptyRepositoryException` to indicate that operations cannot proceed
 * on an empty repository.
 *
 * @param repositorySize The size of the repository to validate.
 * @throws EmptyRepositoryException if the repository is empty.
 */
void ValidateEmptyRepository(size_t repositorySize);

#endif