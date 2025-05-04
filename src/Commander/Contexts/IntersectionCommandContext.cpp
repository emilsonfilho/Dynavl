#include "Commander/Contexts/IntersectionCommandContext.hpp"

IntersectionCommandContext::IntersectionCommandContext(Repository repository,
                                                       int index1, int index2)
    : DoubleIndexedCommandContext(repository, index1, index2) {}
