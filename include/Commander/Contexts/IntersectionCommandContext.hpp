#ifndef INTERSECTION_CONTEXT_COMMAND_HPP
#define INTERSECTION_CONTEXT_COMMAND_HPP

#include <string>

#include "../def/Repository.hpp"
#include "Commander/Contexts/DoubleIndexedCommandContext.hpp"

using std::string;

class IntersectionCommandContext
    : public DoubleIndexedCommandContext<Repository> {
public:
  IntersectionCommandContext(Repository repository, int index1, int index2);
};

#endif
