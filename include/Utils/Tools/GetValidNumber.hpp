#ifndef GET_VALID_NUMBER_HPP
#define GET_VALID_NUMBER_HPP

#include "../def/IntValidator.hpp"
#include "Exceptions/InvalidArgumentException.hpp"
#include "Messages/InvalidArgumentForNumberMessage.hpp"
#include "Utils/Tools/IgnoreCin.hpp"

using std::cin;
using std::cout;
using std::exception;
using std::string;

/**
 * @brief Reads a valid integer from the user
 *
 * This function goes into an infinite loop unless the user types something
 * valid. Something is defined as valid in the parameter that receives a series
 * of validations given by the program, making it flexible for various cases.
 * I.e., there will always be a valid value. Furthermore, this function only
 * handles integer requests. If needed is a function that reads another value,
 * another function must be created.
 *
 * @param prompt The message asking what you want from the user
 * @param validations A series of validations that will indicate whether the
 * answer given is valid
 *
 * @throws InvalidArgumentException If the user types something invalid
 */
int getValidNumber(const string &prompt, const IntValidator validations);

#endif