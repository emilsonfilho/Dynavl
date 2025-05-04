#ifndef SWAP_COMMAND_CONTEXT
#define SWAP_COMMAND_CONTEXT

#include "../def/ConstRepository.hpp"
#include "Commander/Contexts/DoubleIndexedCommandContext.hpp"

class SwapCommandContext : public DoubleIndexedCommandContext<ConstRepository> {
public:
  SwapCommandContext(ConstRepository repository, int index1, int index2);
};

#endif
