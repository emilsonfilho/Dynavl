#ifndef LIST_CONTEXT_COMMAND_HPP
#define LIST_CONTEXT_COMMAND_HPP

#include "../def/ConstRepository.hpp"
#include "Commander/Contexts/CommandContext.hpp"

class ListCommandContext : public CommandContext {
public:
  ConstRepository repository;

  ListCommandContext(ConstRepository repository);
};

#endif
