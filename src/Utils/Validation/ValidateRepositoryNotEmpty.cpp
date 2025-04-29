#include "Utils/Validation/ValidateRepositoryNotEmpty.hpp"

void ValidateRepositoryNotEmpty(const Repository repositorySize) {
	ValidateEmptyRepository(repositorySize.size());
}