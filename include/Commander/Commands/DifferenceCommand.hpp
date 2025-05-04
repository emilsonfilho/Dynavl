#ifndef DIFFERENCE_COMMAND_HPP
#define DIFFERENCE_COMMAND_HPP

#include <iostream>

#include "Commander/Commands/Command.hpp"
#include "Commander/Contexts/DifferenceCommandContext.hpp"
#include "Utils/Tools/FormatOrigin.hpp"

using std::cout;

class DifferenceCommand : public Command {
public:
  /**
   * @brief Constructs a DifferenceCommand with the given name and
   * description.
   *
   * Initializes the base Command class using the provided name and description,
   * setting up the command to perform a union operation between two sets.
   *
   * @param name The name of the command.
   * @param description A brief description of what the command does.
   */
  DifferenceCommand(const string &name, const string &description);

  void execute(CommandContext *context) const override;
};

#endif
