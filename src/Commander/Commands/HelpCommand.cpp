#include "Commander/Commands/HelpCommand.hpp"

HelpCommand::HelpCommand(const string &name,
                         const string &description,
                         const UnorderedMapCommand &mapCommand)
    : Command(name, description), commandRegistry(mapCommand) {}

void HelpCommand::execute(CommandContext *context) const {
  (void)context;
  ostringstream ss;

  for (const auto &pair : commandRegistry) {
    ss << pair.first << " - " << pair.second.command->getDescription() << '\n';
  }

  cout << ss.str();
}