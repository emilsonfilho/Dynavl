#ifndef CONTAINS_COMMAND_HPP
#define CONTAINS_COMMAND_HPP

#include <iostream>

using std::string;
using std::cout;

#include "Commander/Commands/Command.hpp"
#include "Commander/Contexts/ContainsCommandContext.hpp"

class ContainsCommand : public Command {
public:
    /*
     * @brief ContainsCommand constructor
     */
    ContainsCommand(const string& name, const string& description);

    /*
     * @brief ContainsCommand execution function
     * 
     * @param context Command context
     */
    void execute(CommandContext *context) const override;
};

#endif