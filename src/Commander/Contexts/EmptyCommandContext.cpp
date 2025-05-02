#include "Commander/Contexts/EmptyCommandContext.hpp"

EmptyCommandContext::EmptyCommandContext(ConstRepository repository, int index)
	: IndexedCommandContext(repository, index) {}
