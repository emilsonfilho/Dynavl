#ifndef UNION_CONTEXT_COMMAND_HPP
#define UNION_CONTEXT_COMMAND_HPP

#include <string>

#include "Commander/Contexts/DoubleIndexedCommandContext.hpp"

using std::string;

class UnionCommandContext : public DoubleIndexedCommandContext<Repository> {
public:
  /**
   * @brief Context builder to join two sets on the system
   *
   * @param repository DI for data from the running system
   */
  UnionCommandContext(Repository repository, int index1, int index2);
};

#endif
