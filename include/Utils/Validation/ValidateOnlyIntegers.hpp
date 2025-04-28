#ifndef VALIDATE_ONLY_INTEGERS_HPP
#define VALIDATE_ONLY_INTEGERS_HPP

#include <string>
#include <sstream>

#include "Exceptions/InvalidNumberInputException.hpp"
#include "Messages/InvalidNumberInputMessage.hpp"

using std::istringstream;
using std::isdigit;

/**
 * @brief Validates whether a string contains only integer tokens separated by spaces.
 *
 * This function reads the input string token by token and checks if each token
 * consists only of digit characters. If any token is invalid, it throws an exception.
 * The function ensures that the entire string is processed and only valid integer tokens
 * are present.
 *
 * @param str The string to validate.
 * @throws InvalidNumberInputException if the string contains non-integer tokens or is improperly formatted.
 */
void ValidateOnlyIntegers(const string& str);

#endif