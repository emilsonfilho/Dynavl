#include "Utils/Tools/GetValidNumber.hpp"

int getValidNumber(const string &prompt,
                   const IntValidatorArray validations) {
  int num = -1;

  while (true) {
    try {
      cout << prompt;

      if (!(cin >> num))
        throw InvalidArgumentException(InvalidArgumentForNumberMessage());

      for (const auto &validate : validations) {
        validate(num);
      }

      break;
    } catch (const exception &e) {
      cout << e.what() << "\n";
      cin.clear();
      ignoreCin();
    }
  }

  ignoreCin();

  return num;
}