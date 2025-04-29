#ifndef EMPTY_COMMAND_CONTEXT_HPP
#define EMPTY_COMMAND_CONTEXT_HPP

#include "../def/Repository.hpp"
#include "Commander/Contexts/CommandContext.hpp"

using std::string;

class EmptyCommandContext : public CommandContext {
public:
  Repository repository;
  int index;

  /**
   * @brief Context builder to empty command
   *
   * @param repository DI for data from the running system
   */
  EmptyCommandContext(const Repository repository, int index);
};

#endif