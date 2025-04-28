#ifndef SHOW_COMMAND_HPP
#define SHOW_COMMAND_HPP

#include <string>

using std::string;

#include "Commander/Commands/Command.hpp"
#include "Commander/Contexts/ShowCommandContext.hpp"

class ShowCommand : public Command {
public:
	/*
	 * @brief ShowCommand constructor
	 */
	ShowCommand(const string& name, const string& description);

	/*
	 * @brief ShowCommand execution function
	 * 
	 * @param context Command context
	 */
	void execute(CommandContext *context) const override;
};

#endif