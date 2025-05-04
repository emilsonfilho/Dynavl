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
   * @brief DifferenceCommand constructor
   */
  DifferenceCommand(const string &name, const string &description);

  /*
   * @brief DifferenceCommand execution function
   *
   * @param context Command context
   */
  void execute(CommandContext *context) const override;
};

#endif
