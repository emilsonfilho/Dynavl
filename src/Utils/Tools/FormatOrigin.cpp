#include "Utils/Tools/FormatOrigin.hpp"

string formatOrigin(string op, int index1, int index2) {
  string idx1 = to_string(index1), idx2 = to_string(index2);
  return "fomado pela " + op + " entre os conjuntos " + idx1 + " e " + idx2;
}
