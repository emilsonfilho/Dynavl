#include "Commander/Contexts/SuccessorCommandContext.hpp"

SuccessorCommandContext::SuccessorCommandContext(ConstRepository repository,
                                                     int index, int key)
    : IndexedCommandContext(repository, index), key(key) {}
