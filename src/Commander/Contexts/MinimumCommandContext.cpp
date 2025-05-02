#include "Commander/Contexts/MinimumCommandContext.hpp"

MinimumCommandContext::MinimumCommandContext(ConstRepository repository,
                                             int index)
    : IndexedCommandContext(repository, index) {}
