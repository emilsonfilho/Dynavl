#include "Utils/Validation/ValidateIndex.hpp"

void ValidateIndex(int index, int repositorySize) {
    if (index < 0 or index >= repositorySize)
        throw InvalidIndexException(InvalidIndexMessage());
}