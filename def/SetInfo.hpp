#ifndef SET_INFO_HPP
#define SET_INFO_HPP

#include <string>

#include "Set/Set.hpp"

using std::string;

struct SetInfo {
  Set *set;
  string origin;

  SetInfo() = default;
  SetInfo(Set *set, const string &origin) : set(set), origin(origin) {}
};

#endif