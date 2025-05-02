#include "Commander/Contexts/MaximumCommandContext.hpp"

MaximumCommandContext::MaximumCommandContext(ConstRepository repository,
                                             int index)
    : IndexedCommandContext(repository, index) {}
