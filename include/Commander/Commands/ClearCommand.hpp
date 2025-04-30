#ifndef CLEAR_COMMAND_HPP
#define CLEAR_COMMAND_HPP

#include <iostream>

using std::string;
using std::cout;

#include "Commander/Commands/Command.hpp"
#include "Commander/Contexts/ClearCommandContext.hpp"

class ClearCommand : public Command {
public:
	/*
	 * @brief ClearCommand constructor
	 */
	ClearCommand(const string& name, const string& description);

	/*
	 * @brief ClearCommand execution function
	 * 
	 * @param context Command context
	 */
	void execute(CommandContext *context) const override;
};

#endif