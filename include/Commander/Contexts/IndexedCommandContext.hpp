#ifndef INDEXED_COMMAND_HPP
#define INDEXED_COMMAND_HPP

#include "../def/Repository.hpp"
#include "Commander/Contexts/CommandContext.hpp"

class IndexedCommandContext : public CommandContext {
public:
	int index;
	Repository repository;

	IndexedCommandContext(const Repository repository, int index)
		: repository(repository), index(index) {}
};

#endif