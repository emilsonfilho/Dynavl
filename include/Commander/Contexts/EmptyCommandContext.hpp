#ifndef EMPTY_COMMAND_CONTEXT_HPP
#define EMPTY_COMMAND_CONTEXT_HPP

#include "Commander/Contexts/IndexedCommandContext.hpp"

using std::string;

class EmptyCommandContext : public IndexedCommandContext {
public:
  EmptyCommandContext(ConstRepository repository, int index);
};

#endif
