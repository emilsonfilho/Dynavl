#include "Commander/Contexts/DifferenceCommandContext.hpp"

DifferenceCommandContext::DifferenceCommandContext(Repository repository,
                                                   int index1, int index2)
    : DoubleIndexedCommandContext(repository, index1, index2) {}
