#ifndef PREDECESSOR_COMMAND_CONTEXT_HPP
#define PREDECESSOR_COMMAND_CONTEXT_HPP

#include "Commander/Contexts/IndexedCommandContext.hpp"

using std::string;

class PredecessorCommandContext : public IndexedCommandContext {
public:
  int key;

  PredecessorCommandContext(ConstRepository repository, int index, int key);
};

#endif
