#include "Utils/Validation/ValidateOnlyIntegers.hpp"

void ValidateOnlyIntegers(const string& str) {
	istringstream iss(str);
	string token;

	while (iss >> token) {
		try {
			stoi(token);
		} catch (const exception& e) {
			throw InvalidNumberInputException(InvalidNumberInputMessage());
		}
	}

	if (!iss.eof()) throw InvalidNumberInputException(InvalidNumberInputMessage());
}