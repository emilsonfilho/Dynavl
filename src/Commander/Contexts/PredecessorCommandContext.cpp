#include "Commander/Contexts/PredecessorCommandContext.hpp"

PredecessorCommandContext::PredecessorCommandContext(ConstRepository repository,
                                                     int index, int key)
    : IndexedCommandContext(repository, index), key(key) {}
