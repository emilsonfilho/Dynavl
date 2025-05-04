#ifndef CREATE_CONTEXT_COMMAND_HPP
#define CREATE_CONTEXT_COMMAND_HPP

#include <queue>

#include "../def/Repository.hpp"
#include "Commander/Contexts/CommandContext.hpp"

using std::queue;
using std::string;

class CreateCommandContext : public CommandContext {
public:
  Repository repository;
  queue<int> initialData;
  string origin;

  CreateCommandContext(Repository repository, queue<int> &initialData,
                       const string &origin);
};

#endif