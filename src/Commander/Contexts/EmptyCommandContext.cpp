#include "Commander/Contexts/EmptyCommandContext.hpp"

EmptyCommandContext::EmptyCommandContext(const Repository repository, int index)
	: IndexedCommandContext(repository, index) {}