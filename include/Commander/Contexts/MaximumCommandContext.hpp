#ifndef MAXIMUM_COMMAND_CONTEXT_HPP
#define MAXIMUM_COMMAND_CONTEXT_HPP

#include "Commander/Contexts/IndexedCommandContext.hpp"

using std::string;

class MaximumCommandContext : public IndexedCommandContext {
public:
  MaximumCommandContext(ConstRepository repository, int index);
};

#endif
