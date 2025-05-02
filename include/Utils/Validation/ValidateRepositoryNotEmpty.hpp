#ifndef VALIDATE_REPOSITORY_NOT_EMPTY_HPP
#define VALIDATE_REPOSITORY_NOT_EMPTY_HPP

#include "../def/ConstRepository.hpp"
#include "Utils/Validation/ValidateEmptyRepository.hpp"

/**
 * @brief Validates that the repository of sets is not empty.
 *
 * This function checks if the provided vector of sets is empty by calling
 * `ValidateEmptyRepository`. If it is empty, an exception is thrown.
 *
 * @param repository The repository to validate.
 * @throws EmptyRepositoryException if the repository is empty.
 */
void ValidateRepositoryNotEmpty(ConstRepository sets);

#endif
