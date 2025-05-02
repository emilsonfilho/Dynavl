#include "Commander/Contexts/InsertCommandContext.hpp"

InsertCommandContext::InsertCommandContext(ConstRepository repository, int index, int value)
    : IndexedCommandContext(repository, index), value(value) {}
