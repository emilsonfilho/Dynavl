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
    * @brief Constructs a SwapCommand with the given name and description.
    *
    * Initializes the base Command class using the provided name and description,
    * setting up the command to perform a swap operation between two sets.
    *
    * @param name The name of the command.
    * @param description A brief description of what the command does.
    */
    SwapCommand(const string& name, const string& description);

   /**
    * @brief Executes the swap operation between two sets in the repository.
    *
    * This function casts the generic CommandContext to a SwapCommandContext,
    * retrieves the two set indexes, and swaps their contents.
    * It also prints a confirmation message to the user.
    *
    * @param context A pointer to the command context containing the swap details.
    */
    void execute(CommandContext *context) const override;
};

#endif
