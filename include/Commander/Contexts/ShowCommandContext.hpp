#ifndef SHOW_CONTEXT_COMMAND_HPP
#define SHOW_CONTEXT_COMMAND_HPP

#include <queue>

#include "../def/ConstRepository.hpp"
#include "Commander/Contexts/CommandContext.hpp"

using std::queue;
using std::string;

class ShowCommandContext : public CommandContext {
public:
  queue<int> indexes;
  ConstRepository repository;

  ShowCommandContext(ConstRepository repository, const queue<int> &indexes);
};

#endif
