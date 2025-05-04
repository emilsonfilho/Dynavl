#include "Commander/Contexts/CreateCommandContext.hpp"

CreateCommandContext::CreateCommandContext(Repository repository,
                                           queue<int> &initialData,
                                           const string &origin)
    : repository(repository), initialData(initialData), origin(origin) {}