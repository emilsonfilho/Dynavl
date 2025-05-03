#include "Commander/Contexts/UnionCommandContext.hpp"

UnionCommandContext::UnionCommandContext(Repository repository, int index1,
                                         int index2)
    : DoubleIndexedCommandContext(repository, index1, index2) {}
