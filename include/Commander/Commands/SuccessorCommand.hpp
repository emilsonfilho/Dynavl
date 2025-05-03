#ifndef SUCCESSOR_COMMAND_HPP
#define SUCCESSOR_COMMAND_HPP

#include <iostream>

using std::cout;
using std::string;

#include "Commander/Commands/Command.hpp"
#include "Commander/Contexts/SuccessorCommandContext.hpp"

class SuccessorCommand : public Command {
public:
  /*
   * @brief SuccessorCommand constructor
   */
  SuccessorCommand(const string &name, const string &description);

  /*
   * @brief SuccessorCommand execution function
   *
   * @param context Command context
   */
  void execute(CommandContext *context) const override;
};

#endif
