#include "Utils/Tools/Trim.hpp"

string trim(const string &str) {
  size_t first = str.find_first_not_of(" \t\n\r");
  if (first == string::npos)
    return "";
  size_t last = str.find_last_not_of(" \t\n\r");
  string s = str.substr(first, last - first + 1);

  // collapses any whitespace sequence into a single space
  static const regex re("\\s+");
  return regex_replace(s, re, " ");
}