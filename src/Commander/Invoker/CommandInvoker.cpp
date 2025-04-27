#include "Commander/Invoker/CommandInvoker.hpp"

void CommandInvoker::registerCommand(const string &commandName,
                                     Command *command, Context context) {
  if (!context) {
    context = []() -> CommandContext * { return nullptr; };
  }

  commandRegistry[commandName] = CommandInfo{command, context};
}

void CommandInvoker::executeCommand(const string &commandName) {
  if (commandRegistry.find(commandName) == commandRegistry.end())
    throw InvalidCommandException(InvalidCommandMessage());

  CommandInfo &info = commandRegistry[commandName];
  CommandContext *context = info.contextFactory();
  info.command->execute(context);

  delete context;
}

void CommandInvoker::showHelp() {
  HelpCommand help("help", "Exibe uma lista de descrições de cada comando",
                   commandRegistry);
  help.execute();
}