

#ifndef CONTAINS_COMMAND_CONTEXT_HPP
#define CONTAINS_COMMAND_CONTEXT_HPP

#include "../def/Repository.hpp"
#include "Commander/Contexts/CommandContext.hpp"

using std::string;

class ContainsCommandContext : public CommandContext {
public:
    Repository repository;
    int setIndex;
    int key;

    /**
     * @brief Constructs a context for a "contains" command operation.
     *
     * This constructor initializes the context with the given repository, set index,
     * and key to be checked, storing all necessary information for executing the command.
     *
     * @param repository The repository containing the sets.
     * @param setIndex The index of the set within the repository.
     * @param key The key to search for in the specified set.
     */
    ContainsCommandContext(const Repository repository, int setIndex, int key);
};

#endif