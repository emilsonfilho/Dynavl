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

  /**
   * @brief Context builder to create a set on the system
   *
   * @param repository DI for data from the running system
   */
  CreateCommandContext(Repository repository, queue<int>& initialData, const string& origin);
};

#endif