#ifndef PROMPT_VALID_INDEX_HPP
#define PROMPT_VALID_INDEX_HPP 

#include "../def/Repository.hpp"
#include "Utils/Tools/GetValidNumber.hpp"
#include "Utils/Validation/ValidateIndex.hpp"

using std::string;

int promptValidIndex(const Repository repository, const string& prompt);

#endif