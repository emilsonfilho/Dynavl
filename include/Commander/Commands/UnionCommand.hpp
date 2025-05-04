#ifndef UNION_COMMAND_HPP
#define UNION_COMMAND_HPP

#include <iostream>

#include "Commander/Commands/Command.hpp"
#include "Commander/Contexts/UnionCommandContext.hpp"
#include "Utils/Tools/FormatOrigin.hpp"

using std::cout;

class UnionCommand : public Command {
public:
  /**
   * @brief UnionCommmand constructor
   */
  UnionCommand(const string &name, const string &description);
  /*
   * @brief UnionCommand execution function
   *
   * @param context Command context
   */
  void execute(CommandContext *context) const override;
};

#endif
