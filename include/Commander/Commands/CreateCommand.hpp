#ifndef CREATE_COMMAND_HPP
#define CREATE_COMMAND_HPP

#include <string>
#include <vector>
#include <iostream>

#include "Commander/Commands/Command.hpp"
#include "Commander/Contexts/CreateCommandContext.hpp"

using std::string;
using std::cout;
using std::vector;

class CreateCommand : public Command {
public:
	/*
	 * @brief CreateCommand constructor
	 */
	CreateCommand(const string& name, const string& description);

	/*
	 * @brief CreateCommand execution function
	 * 
	 * @param context Command context
	 */
	void execute(CommandContext *context) const override;
};

#endif