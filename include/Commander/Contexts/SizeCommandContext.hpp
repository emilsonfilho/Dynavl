#ifndef SIZE_COMMAND_CONTEXT_HPP
#define SIZE_COMMAND_CONTEXT_HPP

#include "Commander/Contexts/IndexedCommandContext.hpp"

using std::string;

class SizeCommandContext : public IndexedCommandContext {
public:
  /**
   * @brief Context builder to size command
   *
   * @param repository DI for data from the running system
   */
  SizeCommandContext(ConstRepository repository, int index);
};

#endif
