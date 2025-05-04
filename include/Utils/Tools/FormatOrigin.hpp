#ifndef FORMAT_ORIGIN_HPP
#define FORMAT_ORIGIN_HPP

#include <string>

using std::string;
using std::to_string;

/**
 * @brief Formats a description indicating the origin of a result from two sets.
 *
 * This function constructs a string describing that the result was formed by
 * the specified operation between two sets identified by their indexes.
 *
 * @param op The name of the operation performed.
 * @param index1 The index of the first set involved in the operation.
 * @param index2 The index of the second set involved in the operation.
 * @return std::string A formatted description of the operation origin.
 */
string formatOrigin(string op, int index1, int index2);

#endif
