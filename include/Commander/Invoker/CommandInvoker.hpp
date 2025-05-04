#ifndef INVOKER_HPP
#define INVOKER_HPP

#include "Commander/Commands/HelpCommand.hpp"
#include "Exceptions/InvalidCommandException.hpp"
#include "Messages/InvalidCommandMessage.hpp"

using std::string;

using Context = function<CommandContext *()>;

class CommandInvoker {
private:
  UnorderedMapCommand commandRegistry;

public:
  /**
   * @brief Registra um comando para que possa ser executado pelo usuário
   *
   * @param commandName Nome do comando a ser registrado
   * @param command Ponteiro para o arquivo de comando
   * @param context Função geradora do contexto do comando
   */
  void registerCommand(const string &commandName, Command *command,
                       Context context = nullptr);

  /**
   * @brief Executa o comando especificado pelo nome
   *
   * @param commandName Nome do comando a ser executado
   *
   * @throws InvalidCommandException se o comando não for encontrado
   */
  void executeCommand(const string &commandName);
  /**
   * @brief Função invocadora do comando especial HelpCommand
   */
  void showHelp();
};

#endif