#ifndef ERASE_COMMAND_CONTEXT_HPP
#define ERASE_COMMAND_CONTEXT_HPP

#include "Commander/Contexts/IndexedCommandContext.hpp"

using std::string;

class EraseCommandContext : public IndexedCommandContext {
public:
  int key;

  EraseCommandContext(ConstRepository repository, int index, int key);
};

#endif
