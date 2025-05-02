#ifndef MAXIMUM_COMMAND_CONTEXT_HPP
#define MAXIMUM_COMMAND_CONTEXT_HPP

#include "Commander/Contexts/IndexedCommandContext.hpp"

using std::string;

class MaximumCommandContext : public IndexedCommandContext {
public:
  /**
   * @brief Context builder to minimum command
   *
   * @param repository DI for data from the running system
   */
  MaximumCommandContext(ConstRepository repository, int index);
};

#endif
