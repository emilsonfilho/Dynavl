#ifndef INSERT_COMMAND_CONTEXT_HPP
#define INSERT_COMMAND_CONTEXT_HPP

#include "Commander/Contexts/IndexedCommandContext.hpp"

class InsertCommandContext : public IndexedCommandContext {
public:
  int value;

  InsertCommandContext(ConstRepository repository, int index, int value);
};

#endif
