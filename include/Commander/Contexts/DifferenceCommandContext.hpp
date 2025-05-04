#ifndef DIFFERENCE_CONTEXT_COMMAND_HPP
#define DIFFERENCE_CONTEXT_COMMAND_HPP

#include <string>

#include "../def/Repository.hpp"
#include "Commander/Contexts/DoubleIndexedCommandContext.hpp"

using std::string;

class DifferenceCommandContext
    : public DoubleIndexedCommandContext<Repository> {
public:
  DifferenceCommandContext(Repository repository, int index1, int index2);
};

#endif
