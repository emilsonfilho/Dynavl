#ifndef PREDECESSOR_COMMAND_CONTEXT_HPP
#define PREDECESSOR_COMMAND_CONTEXT_HPP

#include "Commander/Contexts/IndexedCommandContext.hpp"

using std::string;

class PredecessorCommandContext : public IndexedCommandContext {
public:
  int key;
  /**
   * @brief Context builder to minimum command
   *
   * @param repository DI for data from the running system
   */
  PredecessorCommandContext(ConstRepository repository, int index, int key);
};

#endif
