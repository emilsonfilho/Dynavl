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

#include "Commander/Commands/CreateCommand.hpp"
#include "Commander/Commands/ShowCommand.hpp"
#include "Commander/Invoker/CommandInvoker.hpp"

#include "Utils/Validation/ValidateEmptyRepository.hpp"
#include "Utils/Validation/ValidateOnlyIntegers.hpp"

#include "Utils/Tools/GetValidString.hpp"

using std::vector;
using std::cout;
using std::string;
using std::getline;
using std::cin;
using std::exception;
// using std::endl;

int main() {
	CommandInvoker invoker;
	vector<SetInfo> sets;

	CreateCommand createCommand("create", "cria um conjunto com ou sem valores");
	ShowCommand showCommand("show", "mostra os conjuntos do sistema");

	invoker.registerCommand(
		createCommand.getName(), &createCommand, [&sets]() -> CommandContext * {
			istringstream bufferedData(getValidString(PromptSetNumbers,
					{[&](const string& data) {
						ValidateOnlyIntegers(data);
					}}));
			
			int num;
			queue<int> data;
			while (bufferedData >> num) data.push(num);

			return new CreateCommandContext(sets, data, "criado por linha de comando");
		}
	);

	invoker.registerCommand(
		showCommand.getName(), &showCommand, [&sets]() -> CommandContext * {
			ValidateEmptyRepository(sets.size());
			istringstream bufferedData(getValidString(PromptShowSets,
					{[&](const string& data) {
						ValidateOnlyIntegers(data);
					}}));
			
			int num;
			queue<int> data;
			while (bufferedData >> num) data.push(num);

			return new ShowCommandContext(sets, data);
		}
	);

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