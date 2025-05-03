#ifndef UNION_COMMAND_HPP
#define UNION_COMMAND_HPP

#include <iostream>

#include "Commander/Commands/Command.hpp"
#include "Commander/Contexts/UnionCommandContext.hpp"
#include "Utils/Tools/FormatOrigin.hpp"

using std::cout;

class UnionCommand : public Command {
public:
  /**
   * @brief Constructs a UnionCommand with the given name and description.
   *
   * Initializes the base Command class using the provided name and description,
   * setting up the command to perform a swap operation between two sets.
   *
   * @param name The name of the command.
   * @param description A brief description of what the command does.
   */
  UnionCommand(const string &name, const string &description);

  void execute(CommandContext *context) const override;
};

#endif
