#ifndef TRIM_HPP
#define TRIM_HPP

#include <algorithm>
#include <cctype>
#include <string>
#include <regex>

using std::string;
using std::regex;

/**
 * @brief Removes whitespace from the beginning and end of a string
 *
 * @param str String to be treated
 * @return std::string String treated
 */
string trim(const string &str);

#endif