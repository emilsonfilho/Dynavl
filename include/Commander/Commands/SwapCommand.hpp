#ifndef SWAP_COMMAND_HPP
#define SWAP_COMMAND_HPP

#include <iostream>

#include "Commander/Commands/Command.hpp"
#include "Commander/Contexts/SwapCommandContext.hpp"

using std::string;
using std::cout;

class SwapCommand : public Command {
public:
   /**
    * @briefSwapCommad constructor
    */
    SwapCommand(const string& name, const string& description);

   /*
    * @brief ContainsCommand execution function
    * 
    * @param context Command context
    */
   void execute(CommandContext *context) const override;
};

#endif
