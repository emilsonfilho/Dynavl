#ifndef SUCCESSOR_COMMAND_CONTEXT_HPP
#define SUCCESSOR_COMMAND_CONTEXT_HPP

#include "Commander/Contexts/IndexedCommandContext.hpp"

using std::string;

class SuccessorCommandContext : public IndexedCommandContext {
public:
  int key;
  /**
   * @brief Context builder to minimum command
   *
   * @param repository DI for data from the running system
   */
  SuccessorCommandContext(ConstRepository repository, int index, int key);
};

#endif
