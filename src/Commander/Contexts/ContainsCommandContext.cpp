#include "Commander/Contexts/ContainsCommandContext.hpp"

ContainsCommandContext::ContainsCommandContext(const Repository repository, int index, int key)
    : IndexedCommandContext(repository, index), key(key) {}