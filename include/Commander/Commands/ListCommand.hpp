#ifndef LIST_COMMAND_HPP
#define LIST_COMMAND_HPP

#include <iostream>
#include <string>

using std::cout;
using std::string;

#include "Commander/Commands/Command.hpp"
#include "Commander/Contexts/ListCommandContext.hpp"

class ListCommand : public Command {
public:
  /*
   * @brief ListCommand constructor
   */
  ListCommand(const string &name, const string &description);

  /*
   * @brief ListCommand execution function
   *
   * @param context Command context
   */
  void execute(CommandContext *context) const override;
};

#endif
