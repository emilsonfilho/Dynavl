#include "Commander/Contexts/SwapCommandContext.hpp"

SwapCommandContext::SwapCommandContext(ConstRepository repository, int index1, int index2)
    : repository(repository), index1(index1), index2(index2) {}
