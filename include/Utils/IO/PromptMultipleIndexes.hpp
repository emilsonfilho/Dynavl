#ifndef PROMPT_MULTIPLE_INDEXES
#define PROMPT_MULTIPLE_INDEXES 

#include <queue>

#include "../def/ConstRepository.hpp"
#include "Utils/Tools/GetValidString.hpp"
#include "Utils/Validation/ValidateOnlyIntegers.hpp"
#include "Utils/Validation/ValidateIndexes.hpp"

using std::queue;
using std::string;
using std::istringstream;

/**
 * @brief Prompts the user for multiple set indexes and validates them.
 *
 * This function prompts the user with a given message, validates that the input
 * contains only integers and that each index is within the valid repository range.
 * It then returns the validated indexes stored in a queue.
 *
 * @param repository The repository containing the sets.
 * @param prompt The message to display to the user.
 * @return std::queue<int> A queue containing the validated indexes.
 * @throws InvalidNumberInputException if non-integer input is provided.
 * @throws InvalidIndexException if any index is out of bounds.
 */
queue<int> promptMultipleIndexes(ConstRepository repository, const string& prompt);

#endif
