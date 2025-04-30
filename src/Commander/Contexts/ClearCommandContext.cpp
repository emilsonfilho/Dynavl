#include "Commander/Contexts/ClearCommandContext.hpp"

ClearCommandContext::ClearCommandContext(const Repository repository, int index)
    : IndexedCommandContext(repository, index) {}