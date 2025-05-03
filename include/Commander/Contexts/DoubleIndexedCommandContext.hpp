#ifndef DOUBLE_INDEXED_COMMAND_HPP
#define DOUBLE_INDEXED_COMMAND_HPP

#include "../def/ConstRepository.hpp"
#include "Commander/Contexts/CommandContext.hpp"

/**
 * @class DoubleIndexedCommandContext
 * @brief Represents a command context that includes two indexes and a
 * repository.
 *
 * This class extends the CommandContext and adds additional information
 * such as two indexes to identify a specific command and a repository
 * to provide context for the command's execution.
 */
 template <typename R>
class DoubleIndexedCommandContext : public CommandContext {
public:
  ConstRepository repository;
  int index1;
  int index2;

  /**
   * @brief Constructs an DoubleIndexedCommandContext with the given repository
   * and indexes.
   * @param repository The repository associated with the command.
   * @param index1 The first index of the command.
   * @param index2 The second index of the command.
   */
  DoubleIndexedCommandContext(R repository, int index1,
                              int index2)
      : repository(repository), index1(index1), index2(index2) {}
};

#endif
