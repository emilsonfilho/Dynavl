#include "Utils/Tools/Trim.hpp"

string trim(const string &str) {
  size_t first = str.find_first_not_of(" \t\n\r");
  if (first == string::npos)
    return "";
  size_t last = str.find_last_not_of(" \t\n\r");
  return str.substr(first, last - first + 1);
}