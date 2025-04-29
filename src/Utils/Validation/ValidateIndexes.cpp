#include "Utils/Validation/ValidateIndexes.hpp"

// The function who calls it GUARANTEES that the string only contains numbers separated by whitespaces
void ValidateIndexes(const string& data, int repositorySize) {
	istringstream iss(data);
	int num;

	while (iss >> num) 
		if (num < 0 or num >= repositorySize)
			throw InvalidIndexStringException(InvalidIndexStringMessage());
}