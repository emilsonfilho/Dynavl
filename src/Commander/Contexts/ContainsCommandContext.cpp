#include "Commander/Contexts/ContainsCommandContext.hpp"

ContainsCommandContext::ContainsCommandContext(ConstRepository repository,
                                               int index, int key)
    : IndexedCommandContext(repository, index), key(key) {}
