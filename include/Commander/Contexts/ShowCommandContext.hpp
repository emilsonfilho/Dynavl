#ifndef SHOW_CONTEXT_COMMAND_HPP
#define SHOW_CONTEXT_COMMAND_HPP

#include <queue>

#include "../def/Repository.hpp"
#include "Commander/Contexts/CommandContext.hpp"

using std::string;
using std::queue;

class ShowCommandContext : public CommandContext {
public:
  queue<int> indexes;
  Repository repository;

  /**
   * @brief Context builder to Show command
   *
   * @param repository DI for data from the running system
   */
  ShowCommandContext(const Repository repository, const queue<int>& indexes);
};

#endif