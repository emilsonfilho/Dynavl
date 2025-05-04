#ifndef VALIDATE_INDEX_HPP
#define VALIDATE_INDEX_HPP

#include "Exceptions/InvalidIndexException.hpp"
#include "Messages/InvalidIndexMessage.hpp"

/**
 * @brief Validates whether an index is within the valid range of a repository.
 *
 * This function checks if the given index is non-negative and less than the
 * repository size. If the index is out of bounds, it throws an
 * `InvalidIndexException`.
 *
 * @param index The index to validate.
 * @param repositorySize The size of the repository to validate against.
 * @throws InvalidIndexException if the index is invalid.
 */
void ValidateIndex(int index, int repositorySize);

#endif