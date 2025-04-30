#ifndef INDEXED_COMMAND_HPP
#define INDEXED_COMMAND_HPP

#include "../def/Repository.hpp"
#include "Commander/Contexts/CommandContext.hpp"

/**
 * @class IndexedCommandContext
 * @brief Represents a command context that includes an index and a repository.
 * 
 * This class extends the CommandContext and adds additional information
 * such as an index to identify a specific command and a repository
 * to provide context for the command's execution.
 */
class IndexedCommandContext : public CommandContext {
public:
    /**
     * @brief The index of the command within a sequence or collection.
     */
    int index;

    /**
     * @brief The repository associated with the command's context.
     */
    Repository repository;

    /**
     * @brief Constructs an IndexedCommandContext with the given repository and index.
     * @param repository The repository associated with the command.
     * @param index The index of the command.
     */
    IndexedCommandContext(const Repository repository, int index)
        : repository(repository), index(index) {}
};

#endif