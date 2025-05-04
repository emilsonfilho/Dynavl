#ifndef INSERT_COMMAND_HPP
#define INSERT_COMMAND_HPP

#include <iostream>

using std::cout;
using std::string;

#include "Commander/Commands/Command.hpp"
#include "Commander/Contexts/InsertCommandContext.hpp"

class InsertCommand : public Command {
public:
  /*
   * @brief InsertCommand constructor
   */
  InsertCommand(const string &name, const string &description);

  /*
   * @brief InsertCommand execution function
   *
   * @param context Command context
   */
  void execute(CommandContext *context) const override;
};

#endif