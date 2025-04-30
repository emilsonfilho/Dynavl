#ifndef SIZE_COMMAND_HPP
#define SIZE_COMMAND_HPP

#include <iostream>

using std::string;
using std::cout;

#include "Commander/Commands/Command.hpp"
#include "Commander/Contexts/SizeCommandContext.hpp"

class SizeCommand : public Command {
public:
	/*
	 * @brief SizeCommand constructor
	 */
	SizeCommand(const string& name, const string& description);

	/*
	 * @brief SizeCommand execution function
	 * 
	 * @param context Command context
	 */
	void execute(CommandContext *context) const override;
};

#endif