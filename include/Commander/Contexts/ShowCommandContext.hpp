#ifndef SHOW_CONTEXT_COMMAND_HPP
#define SHOW_CONTEXT_COMMAND_HPP

#include <queue>

#include "../def/ConstRepository.hpp"
#include "Commander/Contexts/CommandContext.hpp"

using std::string;
using std::queue;

class ShowCommandContext : public CommandContext {
public:
  queue<int> indexes;
  ConstRepository repository;

  /**
   * @brief Context builder to Show command
   *
   * @param repository DI for data from the running system
   */
  ShowCommandContext(ConstRepository repository, const queue<int>& indexes);
};

#endif
