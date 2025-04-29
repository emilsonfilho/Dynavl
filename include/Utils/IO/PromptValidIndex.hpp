#ifndef PROMPT_VALID_INDEX_HPP
#define PROMPT_VALID_INDEX_HPP 

#include "../def/Repository.hpp"
#include "Utils/Tools/GetValidNumber.hpp"
#include "Utils/Validation/ValidateIndex.hpp"

using std::string;

/**
 * @brief Prompts the user with a message and retrieves a validated repository index.
 *
 * This function displays the given prompt, reads an integer from the user,
 * and ensures it falls within the valid range [0, repository.size()). It uses
 * `getValidNumber` with a custom validator to enforce the index bounds.
 *
 * @param repository The repository used to determine the valid index range.
 * @param prompt The message displayed to the user when requesting input.
 * @return int A valid index within the repository.
 */
int promptValidIndex(const Repository repository, const string& prompt);

#endif