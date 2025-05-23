/**
 * Autor: Francisco Emilson Santos Souza Filho - Matrícula 565685
 * Data Inicial: 26/04/2025
 *
 * Entrega da Avaliação Continuada 02
 *
 * Disciplina: Estrutura de Dados Avançada
 * Professor: Atílio Gomes
 *
 * Bachalerenado em Ciência da Computação
 * Universidade Federal do Ceará (UFC) - Campus Quixadá
 */

#include <iostream>
#include <vector>

#include "def/SetInfo.hpp"
#include "def/UserQuestions.hpp"

#include "Commander/Commands/ClearCommand.hpp"
#include "Commander/Commands/ContainsCommand.hpp"
#include "Commander/Commands/CreateCommand.hpp"
#include "Commander/Commands/DifferenceCommand.hpp"
#include "Commander/Commands/EmptyCommand.hpp"
#include "Commander/Commands/EraseCommand.hpp"
#include "Commander/Commands/InsertCommand.hpp"
#include "Commander/Commands/IntersectionCommand.hpp"
#include "Commander/Commands/ListCommand.hpp"
#include "Commander/Commands/MaximumCommand.hpp"
#include "Commander/Commands/MinimumCommand.hpp"
#include "Commander/Commands/PredecessorCommand.hpp"
#include "Commander/Commands/ShowCommand.hpp"
#include "Commander/Commands/SizeCommand.hpp"
#include "Commander/Commands/SuccessorCommand.hpp"
#include "Commander/Commands/SwapCommand.hpp"
#include "Commander/Commands/UnionCommand.hpp"
#include "Commander/Invoker/CommandInvoker.hpp"

#include "Utils/Validation/ValidateOnlyIntegers.hpp"
#include "Utils/Validation/ValidateRepositoryNotEmpty.hpp"

#include "Utils/IO/PromptMultipleIndexes.hpp"
#include "Utils/IO/PromptValidIndex.hpp"
#include "Utils/Tools/GetValidString.hpp"

using std::cin;
using std::exception;
using std::getline;

int main() {
  CommandInvoker invoker;
  vector<SetInfo> sets;

  CreateCommand createCommand("create", "cria um conjunto com ou sem valores");
  ShowCommand showCommand("show", "mostra os conjuntos do sistema");
  ContainsCommand containsCommand(
      "contains",
      "verifica se um conjunto do sistema possui um valor especificado");
  EmptyCommand emptyCommand("empty",
                            "verifica se um conjunto do sistema esta vazio");
  SizeCommand sizeCommand("size", "extrai o tamanho de um conjunto do sistema");
  InsertCommand insertCommand("insert",
                              "insere um valor em um conjunto do sistema");
  ClearCommand clearCommand(
      "clear", "remove todos os valores de um conjunto do sistema");
  SwapCommand swapCommand("swap", "troca dois conjuntos no sistema");
  EraseCommand eraseCommand("erase",
                            "remove um valor dado de um conjunto do sistema");
  MinimumCommand minimumCommand("minimum", "diz o menor valor em um conjunto");
  MaximumCommand maximumCommand("maximum", "diz o menor valor em um conjunto");
  PredecessorCommand predecessorCommand(
      "predecessor", "exibe o antecessor de um dado numero de um conjunto");
  SuccessorCommand successorCommand(
      "successor", "exibe o sucessor de um dado numero de um conjunto");
  UnionCommand unionCommand("union", "une dois conjuntos do sistema");
  IntersectionCommand intersectionCommand(
      "intersection",
      "reune os elementos em comum de dois conjuntos do sistema");
  DifferenceCommand differenceCommand(
      "difference", "extrai todos os elementos exclusivos do primeiro em "
                    "relacao a uniao de dois conjuntos no sistema");
  ListCommand listCommand("list",
                          "lista a origem de todos os conjuntos do sistema");

  invoker.registerCommand(
      createCommand.getName(), &createCommand, [&sets]() -> CommandContext * {
        istringstream bufferedData(
            getValidString(PromptSetNumbers, [&](const string &data) {
              ValidateOnlyIntegers(data);
            }));

        int num;
        queue<int> data;
        while (bufferedData >> num)
          data.push(num);

        return new CreateCommandContext(sets, data,
                                        "criado por linha de comando");
      });

  invoker.registerCommand(
      showCommand.getName(), &showCommand, [&sets]() -> CommandContext * {
        ValidateRepositoryNotEmpty(sets);

        queue<int> data = promptMultipleIndexes(sets, PromptShowSets);

        return new ShowCommandContext(sets, data);
      });

  invoker.registerCommand(
      containsCommand.getName(), &containsCommand,
      [&sets]() -> CommandContext * {
        ValidateRepositoryNotEmpty(sets);

        int index = promptValidIndex(sets, PromptIndexSet);
        int value =
            getValidNumber(PrompRequestFetchValue, [](const int data) {});

        return new ContainsCommandContext(sets, index, value);
      });

  invoker.registerCommand(emptyCommand.getName(), &emptyCommand,
                          [&sets]() -> CommandContext * {
                            ValidateRepositoryNotEmpty(sets);

                            int index = promptValidIndex(sets, PromptIndexSet);

                            return new EmptyCommandContext(sets, index);
                          });

  invoker.registerCommand(sizeCommand.getName(), &sizeCommand,
                          [&sets]() -> CommandContext * {
                            ValidateRepositoryNotEmpty(sets);

                            int index = promptValidIndex(sets, PromptIndexSet);

                            return new SizeCommandContext(sets, index);
                          });

  invoker.registerCommand(
      insertCommand.getName(), &insertCommand, [&sets]() -> CommandContext * {
        ValidateRepositoryNotEmpty(sets);

        int index = promptValidIndex(sets, PromptIndexSet);
        int value = getValidNumber(PromptInsertNumber, [](const int data) {});

        return new InsertCommandContext(sets, index, value);
      });

  invoker.registerCommand(clearCommand.getName(), &clearCommand,
                          [&sets]() -> CommandContext * {
                            ValidateRepositoryNotEmpty(sets);

                            int index = promptValidIndex(sets, PromptIndexSet);

                            return new ClearCommandContext(sets, index);
                          });

  invoker.registerCommand(
      swapCommand.getName(), &swapCommand, [&sets]() -> CommandContext * {
        ValidateRepositoryNotEmpty(sets);

        int index1 = promptValidIndex(sets, PromptIndexFirstSet),
            index2 = promptValidIndex(sets, PromptIndexSecondSet);

        return new SwapCommandContext(sets, index1, index2);
      });

  invoker.registerCommand(
      eraseCommand.getName(), &eraseCommand, [&sets]() -> CommandContext * {
        ValidateRepositoryNotEmpty(sets);

        int index = promptValidIndex(sets, PromptIndexSet),
            key = getValidNumber(PromptEraseNumber, [](const int data) {});

        return new EraseCommandContext(sets, index, key);
      });

  invoker.registerCommand(minimumCommand.getName(), &minimumCommand,
                          [&sets]() -> CommandContext * {
                            ValidateRepositoryNotEmpty(sets);

                            int index = promptValidIndex(sets, PromptIndexSet);

                            return new MinimumCommandContext(sets, index);
                          });

  invoker.registerCommand(maximumCommand.getName(), &maximumCommand,
                          [&sets]() -> CommandContext * {
                            ValidateRepositoryNotEmpty(sets);

                            int index = promptValidIndex(sets, PromptIndexSet);

                            return new MaximumCommandContext(sets, index);
                          });

  invoker.registerCommand(
      predecessorCommand.getName(), &predecessorCommand,
      [&sets]() -> CommandContext * {
        ValidateRepositoryNotEmpty(sets);

        int index = promptValidIndex(sets, PromptIndexSet),
            key =
                getValidNumber(PromptPredecessorNumber, [](const int data) {});

        return new PredecessorCommandContext(sets, index, key);
      });

  invoker.registerCommand(
      successorCommand.getName(), &successorCommand,
      [&sets]() -> CommandContext * {
        ValidateRepositoryNotEmpty(sets);

        int index = promptValidIndex(sets, PromptIndexSet),
            key = getValidNumber(PromptSuccessorNumber, [](const int data) {});

        return new SuccessorCommandContext(sets, index, key);
      });

  invoker.registerCommand(
      unionCommand.getName(), &unionCommand, [&sets]() -> CommandContext * {
        ValidateRepositoryNotEmpty(sets);

        int index1 = promptValidIndex(sets, PromptIndexFirstSet),
            index2 = promptValidIndex(sets, PromptIndexSecondSet);

        return new UnionCommandContext(sets, index1, index2);
      });

  invoker.registerCommand(
      intersectionCommand.getName(), &intersectionCommand,
      [&sets]() -> CommandContext * {
        ValidateRepositoryNotEmpty(sets);

        int index1 = promptValidIndex(sets, PromptIndexFirstSet),
            index2 = promptValidIndex(sets, PromptIndexSecondSet);

        return new IntersectionCommandContext(sets, index1, index2);
      });

  invoker.registerCommand(
      differenceCommand.getName(), &differenceCommand,
      [&sets]() -> CommandContext * {
        ValidateRepositoryNotEmpty(sets);

        int index1 = promptValidIndex(sets, PromptIndexFirstSet),
            index2 = promptValidIndex(sets, PromptIndexSecondSet);

        return new DifferenceCommandContext(sets, index1, index2);
      });

  invoker.registerCommand(listCommand.getName(), &listCommand,
                          [&sets]() -> CommandContext * {
                            ValidateRepositoryNotEmpty(sets);

                            return new ListCommandContext(sets);
                          });

  while (true) {
    try {
      string input;
      cout << "$";
      getline(cin, input);
      input = trim(input);

      if (input == "help") {
        cout << "help - exibe uma lista dos comandos disponiveis\n";
        invoker.showHelp();
        cout << "exit - fecha a aplicacao\n";
      } else if (input == "exit") {
        for (SetInfo &setInfo : sets) {
          delete setInfo.set;
        }

        sets.clear();

        break;
      } else {
        invoker.executeCommand(input);
      }
    } catch (const exception &e) {
      cout << e.what() << '\n';
    }
  }

  cout << "Ate mais!\n";

  return 0;
}
