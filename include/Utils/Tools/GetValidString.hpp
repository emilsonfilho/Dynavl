#ifndef GET_VALID_STRING_HPP
#define GET_VALID_STRING_HPP

#include <iostream>

#include "../def/StringValidatorArray.hpp"
#include "Exceptions/InvalidArgumentException.hpp"
#include "Utils/Tools/Trim.hpp"

using std::cin;
using std::cout;
using std::exception;
using std::string;

/**
 * @brief Gets a valid string
 *
 * @param prompt Message to be displayed
 * @param validations Validations
 * @return std::string Valid string
 */
std::string getValidString(const string &prompt,
                           const StringValidator validations);

#endif