#ifndef VALIDATE_INDEXES
#define VALIDATE_INDEXES 

#include "Exceptions/InvalidArgumentException.hpp"
#include "Messages/InvalidIndexStringMessage.hpp"

#include <string>
#include <sstream>

using std::string;
using std::istringstream;

void ValidateIndexes(const string &data, size_t repositorySize);

#endif