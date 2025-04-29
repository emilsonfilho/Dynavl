#ifndef PROMPT_MULTIPLE_INDEXES
#define PROMPT_MULTIPLE_INDEXES 

#include <queue>

#include "../def/Repository.hpp"
#include "Utils/Tools/GetValidString.hpp"
#include "Utils/Validation/ValidateOnlyIntegers.hpp"
#include "Utils/Validation/ValidateIndexes.hpp"

using std::queue;
using std::string;
using std::istringstream;

queue<int> promptMultipleIndexes(const Repository repository, const string& prompt);

#endif