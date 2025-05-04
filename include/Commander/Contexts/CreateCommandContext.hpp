#ifndef CREATE_CONTEXT_COMMAND_HPP
#define CREATE_CONTEXT_COMMAND_HPP

#include <queue>

#include "../def/Repository.hpp"
#include "Commander/Contexts/CommandContext.hpp"

using std::string;
using std::queue;

class CreateCommandContext : public CommandContext {
public:
  Repository repository;
  queue<int> initialData;
  string origin;

  CreateCommandContext(Repository repository, queue<int>& initialData, const string& origin);
};

#endif