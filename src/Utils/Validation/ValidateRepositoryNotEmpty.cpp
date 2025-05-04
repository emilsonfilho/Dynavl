#include "Utils/Validation/ValidateRepositoryNotEmpty.hpp"

void ValidateRepositoryNotEmpty(ConstRepository repositorySize) {
  ValidateEmptyRepository(repositorySize.size());
}
