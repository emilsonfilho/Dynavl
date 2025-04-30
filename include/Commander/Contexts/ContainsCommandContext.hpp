

#ifndef CONTAINS_COMMAND_CONTEXT_HPP
#define CONTAINS_COMMAND_CONTEXT_HPP

#include "../def/Repository.hpp"
#include "Commander/Contexts/IndexedCommandContext.hpp"

using std::string;

class ContainsCommandContext : public IndexedCommandContext {
public:
    int key;

    ContainsCommandContext(const Repository repository, int index, int key);
};

#endif