#include "Commander/Contexts/SwapCommandContext.hpp"

SwapCommandContext::SwapCommandContext(ConstRepository repository, int index1,
                                       int index2)
    : DoubleIndexedCommandContext(repository, index1, index2) {}
