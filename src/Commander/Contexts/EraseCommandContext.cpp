#include "Commander/Contexts/EraseCommandContext.hpp"

EraseCommandContext::EraseCommandContext(ConstRepository repository, int index,
                                         int key)
    : IndexedCommandContext(repository, index), key(key) {}
