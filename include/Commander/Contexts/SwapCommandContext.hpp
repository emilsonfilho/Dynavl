#ifndef SWAP_COMMAND_CONTEXT
#define SWAP_COMMAND_CONTEXT

#include "../def/ConstRepository.hpp"
#include "Commander/Contexts/DoubleIndexedCommandContext.hpp"

class SwapCommandContext : public DoubleIndexedCommandContext {
public:
  /**
   * @brief Constructs a context for a "swap" command operation.
   *
   * This constructor initializes the context with a constant reference to the
   * repository and the two indexes of the sets to be swapped.
   *
   * @param repository The constant reference to the repository containing the
   * sets.
   * @param index1 The index of the first set to be swapped.
   * @param index2 The index of the second set to be swapped.
   */
  SwapCommandContext(ConstRepository repository, int index1, int index2);
};

#endif
