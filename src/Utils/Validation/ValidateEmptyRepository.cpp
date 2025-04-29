#include "Utils/Validation/ValidateEmptyRepository.hpp"

void ValidateEmptyRepository(size_t repositorySize) {
	if (repositorySize == 0)
		throw EmptyRepositoryException(EmptyRepositoryMessage());
}