#ifndef INDEXED_COMMAND_HPP
#define INDEXED_COMMAND_HPP

#include "../def/ConstRepository.hpp"
#include "Commander/Contexts/CommandContext.hpp"

class IndexedCommandContext : public CommandContext {
public:
  int index;

  ConstRepository repository;

  IndexedCommandContext(ConstRepository repository, int index)
      : repository(repository), index(index) {}
};

#endif
