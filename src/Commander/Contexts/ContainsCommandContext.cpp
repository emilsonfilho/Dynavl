
#include "Commander/Contexts/ContainsCommandContext.hpp"

ContainsCommandContext::ContainsCommandContext(const Repository repository, int setIndex, int key)
    : repository(repository), setIndex(setIndex), key(key) {}