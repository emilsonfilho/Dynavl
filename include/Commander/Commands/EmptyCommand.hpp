#ifndef EMPTY_COMMAND_HPP
#define EMPTY_COMMAND_HPP

#include <iostream>

using std::string;
using std::cout;

#include "Commander/Commands/Command.hpp"
#include "Commander/Contexts/EmptyCommandContext.hpp"

class EmptyCommand : public Command {
public:
	/*
	 * @brief EmptyCommand constructor
	 */
	EmptyCommand(const string& name, const string& description);

	/*
	 * @brief EmptyCommand execution function
	 * 
	 * @param context Command context
	 */
	void execute(CommandContext *context) const override;
};

#endif