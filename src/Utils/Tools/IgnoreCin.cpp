#include "Utils/Tools/IgnoreCin.hpp"

void ignoreCin() {
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
}