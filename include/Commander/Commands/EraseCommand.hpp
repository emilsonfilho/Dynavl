#ifndef ERASE_COMMAND_HPP
#define ERASE_COMMAND_HPP

#include <iostream>

using std::cout;
using std::string;

#include "Commander/Commands/Command.hpp"
#include "Commander/Contexts/EraseCommandContext.hpp"

class EraseCommand : public Command {
public:
  /*
   * @brief EraseCommand constructor
   */
  EraseCommand(const string &name, const string &description);

  /*
   * @brief EraseCommand execution function
   *
   * @param context Command context
   */
  void execute(CommandContext *context) const override;
};

#endif
