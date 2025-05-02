#ifndef ERASE_COMMAND_CONTEXT_HPP
#define ERASE_COMMAND_CONTEXT_HPP

#include "Commander/Contexts/IndexedCommandContext.hpp"

using std::string;

class EraseCommandContext : public IndexedCommandContext {
public:
  int key;

  /**
   * @brief Constructs an EraseCommandContext with the given repository, set
   * index, and key.
   *
   * Initializes the base IndexedCommandContext with the repository and index,
   * and stores the key to be erased from the set.
   *
   * @param repository The constant reference to the repository containing the
   * sets.
   * @param index The index of the set from which the key will be erased.
   * @param key The key to be erased.
   */
  EraseCommandContext(ConstRepository repository, int index, int key);
};

#endif
