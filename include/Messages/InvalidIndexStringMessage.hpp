#ifndef INVALID_INDEX_STRING_MESSAGE_HPP
#define INVALID_INDEX_STRING_MESSAGE_HPP

#include <string>

using std::string;

/**
 * @brief message to be displayed when a string contains at least one invalid index
 * 
 * An index is considered invalid when it is negative (covered by size_t) or when the index exceeds the limits of the vector
 */
string InvalidIndexStringMessage();

#endif