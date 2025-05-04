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
   * @brief InsertCommand constructor
   */
  IntersectionCommand(const string &name, const string &description);

  /*
   * @brief IntersectionCommand execution function
   * 
   * @param context Command context
   */
  void execute(CommandContext *context) const override;
};

#endif
