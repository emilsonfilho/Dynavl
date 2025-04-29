#include "Utils/IO/PromptMultipleIndexes.hpp"

queue<int> promptMultipleIndexes(const Repository repository, const string& prompt) {
	istringstream bufferedData(getValidString(prompt,
		[&](const string& data) {
			ValidateOnlyIntegers(data);
			ValidateIndexes(data, repository.size());
		}));

	int num;
	queue<int> result;
	while (bufferedData >> num) result.push(num);

	return result;
}