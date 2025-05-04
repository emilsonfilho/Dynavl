#ifndef INTERSECTION_COMMAND_HPP
#define INTERSECTION_COMMAND_HPP

#include <iostream>

#include "Commander/Commands/Command.hpp"
#include "Commander/Contexts/IntersectionCommandContext.hpp"
#include "Utils/Tools/FormatOrigin.hpp"

using std::cout;

class IntersectionCommand : public Command {
public:
  /**
   * @brief Constructs a IntersectionCommand with the given name and
   * description.
   *
   * Initializes the base Command class using the provided name and description,
   * setting up the command to perform a union operation between two sets.
   *
   * @param name The name of the command.
   * @param description A brief description of what the command does.
   */
  IntersectionCommand(const string &name, const string &description);

  void execute(CommandContext *context) const override;
};

#endif
