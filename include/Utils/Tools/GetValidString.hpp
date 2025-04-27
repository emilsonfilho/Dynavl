#ifndef GET_VALID_STRING_HPP
#define GET_VALID_STRING_HPP

#include <iostream>

#include "../def/StringValidatorArray.hpp"
#include "Exceptions/InvalidArgumentException.hpp"
#include "Utils/Tools/Trim.hpp"

using std::string;
using std::cout;
using std::cin;
using std::exception;

/**
 * @brief Gets a valid string
 *
 * @param prompt Message to be displayed
 * @param validations Validations
 * @return std::string Valid string
 */
std::string getValidString(const string &prompt,
                           const StringValidatorArray validations);

#endif