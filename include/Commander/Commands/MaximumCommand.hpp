#ifndef MAXIMUM_COMMAND_HPP
#define MAXIMUM_COMMAND_HPP

#include <iostream>

using std::cout;
using std::string;

#include "Commander/Commands/Command.hpp"
#include "Commander/Contexts/MaximumCommandContext.hpp"

class MaximumCommand : public Command {
public:
  /*
   * @brief MaximumCommand constructor
   */
  MaximumCommand(const string &name, const string &description);

  /*
   * @brief MaximumCommand execution function
   *
   * @param context Command context
   */
  void execute(CommandContext *context) const override;
};

#endif
