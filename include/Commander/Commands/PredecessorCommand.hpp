#ifndef PREDECESSOR_COMMAND_HPP
#define PREDECESSOR_COMMAND_HPP

#include <iostream>

using std::cout;
using std::string;

#include "Commander/Commands/Command.hpp"
#include "Commander/Contexts/PredecessorCommandContext.hpp"

class PredecessorCommand : public Command {
public:
  /*
   * @brief PredecessorCommand constructor
   */
  PredecessorCommand(const string &name, const string &description);

  /*
   * @brief PredecessorCommand execution function
   *
   * @param context Command context
   */
  void execute(CommandContext *context) const override;
};

#endif
