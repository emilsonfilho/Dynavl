#ifndef MINIMUM_COMMAND_HPP
#define MINIMUM_COMMAND_HPP

#include <iostream>

using std::string;
using std::cout;

#include "Commander/Commands/Command.hpp"
#include "Commander/Contexts/MinimumCommandContext.hpp"

class MinimumCommand : public Command {
public:
	/*
	 * @brief MinimumCommand constructor
	 */
	MinimumCommand(const string& name, const string& description);

	/*
	 * @brief MinimumCommand execution function
	 * 
	 * @param context Command context
	 */
	void execute(CommandContext *context) const override;
};

#endif
