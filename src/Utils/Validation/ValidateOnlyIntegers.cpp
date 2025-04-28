#include "Utils/Validation/ValidateOnlyIntegers.hpp"

void ValidateOnlyIntegers(const std::string& str) {
	istringstream iss(str);
	string token;

	while (iss >> token) {
		for (size_t i = 0; i < token.size(); i++){
			if (i == 0 and token[i] == '-' and token.size() > 1)
                continue;
            if (!isdigit(token[i])) 
                throw InvalidNumberInputException(InvalidNumberInputMessage());
		}
	}

	if (!iss.eof())
        throw InvalidNumberInputException(InvalidNumberInputMessage());
}