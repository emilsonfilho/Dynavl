#include "Commander/Contexts/ClearCommandContext.hpp"

ClearCommandContext::ClearCommandContext(ConstRepository repository, int index)
    : IndexedCommandContext(repository, index) {}
