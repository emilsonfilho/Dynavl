#include "Utils/IO/PromptValidIndex.hpp"

int promptValidIndex(ConstRepository repository, const string &prompt) {
  return getValidNumber(
      prompt, [&](int data) { ValidateIndex(data, repository.size()); });
}
