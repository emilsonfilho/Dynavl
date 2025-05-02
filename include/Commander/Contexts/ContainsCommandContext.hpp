#ifndef CONTAINS_COMMAND_CONTEXT_HPP
#define CONTAINS_COMMAND_CONTEXT_HPP

#include "Commander/Contexts/IndexedCommandContext.hpp"

class ContainsCommandContext : public IndexedCommandContext {
public:
    int key;

    ContainsCommandContext(ConstRepository repository, int index, int key);
};

#endif
