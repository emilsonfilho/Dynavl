#ifndef UNION_CONTEXT_COMMAND_HPP
#define UNION_CONTEXT_COMMAND_HPP

#include <string>

#include "../def/Repository.hpp"
#include "Commander/Contexts/DoubleIndexedCommandContext.hpp"

using std::string;

class UnionCommandContext : public DoubleIndexedCommandContext<Repository> {
public:
  UnionCommandContext(Repository repository, int index1, int index2);
};

#endif
