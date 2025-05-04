#ifndef CLEAR_COMMAND_CONTEXT_HPP
#define CLEAR_COMMAND_CONTEXT_HPP

#include "Commander/Contexts/IndexedCommandContext.hpp"

class ClearCommandContext : public IndexedCommandContext {
public:
  ClearCommandContext(ConstRepository repository, int index);
};

#endif
