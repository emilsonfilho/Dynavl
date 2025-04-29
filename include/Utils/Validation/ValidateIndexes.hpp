#ifndef VALIDATE_INDEXES
#define VALIDATE_INDEXES 

#include "Exceptions/InvalidIndexStringException.hpp"
#include "Messages/InvalidIndexStringMessage.hpp"

#include <string>
#include <sstream>

using std::string;
using std::istringstream;

/**
 * @brief Validates that each index in the input string is within the valid range.
 *
 * This function parses the provided string for integer tokens and ensures
 * that each index is between 0 (inclusive) and repositorySize (exclusive).
 * If any index is out of bounds, an exception is thrown.
 *
 * @param data A string containing space-separated integer indexes.
 * @param repositorySize The size of the repository to validate against.
 */
void ValidateIndexes(const string &data, int repositorySize);

#endif