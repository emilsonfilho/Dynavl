#ifndef MINIMUM_COMMAND_CONTEXT_HPP
#define MINIMUM_COMMAND_CONTEXT_HPP

#include "Commander/Contexts/IndexedCommandContext.hpp"

using std::string;

class MinimumCommandContext : public IndexedCommandContext {
public:
  /**
   * @brief Context builder to minimum command
   *
   * @param repository DI for data from the running system
   */
  MinimumCommandContext(ConstRepository repository, int index);
};

#endif
