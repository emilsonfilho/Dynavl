#ifndef COMMAND_INFO_HPP
#define COMMAND_INFO_HPP

#include <functional>

#include "Commander/Commands/Command.hpp"

using std::function;

struct CommandInfo {
  Command *command;
  function<CommandContext *()> contextFactory;
};

#endif