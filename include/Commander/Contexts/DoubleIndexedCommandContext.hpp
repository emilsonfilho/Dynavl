#ifndef DOUBLE_INDEXED_COMMAND_HPP
#define DOUBLE_INDEXED_COMMAND_HPP

#include "Commander/Contexts/CommandContext.hpp"

template <typename R>
class DoubleIndexedCommandContext : public CommandContext {
public:
  R repository;
  int index1;
  int index2;
  
  DoubleIndexedCommandContext(R repository, int index1,
                              int index2)
      : repository(repository), index1(index1), index2(index2) {}
};

#endif
