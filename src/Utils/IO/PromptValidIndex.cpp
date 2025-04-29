#include "Utils/IO/PromptValidIndex.hpp"

int promptValidIndex(const Repository repository, const string& prompt) {
	return getValidNumber(prompt, [&](int data) {
		ValidateIndex(data, repository.size());
	});
}