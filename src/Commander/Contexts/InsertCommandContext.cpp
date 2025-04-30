#include "Commander/Contexts/InsertCommandContext.hpp"

InsertCommandContext::InsertCommandContext(const Repository repository, int index, int value)
    : IndexedCommandContext(repository, index), value(value) {}