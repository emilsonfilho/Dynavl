#include "Utils/Tools/GetValidString.hpp"

string getValidString(const string &prompt,
                           const StringValidatorArray validations) {
  string str;

  while (true) {
    try {
      cout << prompt;
      getline(cin, str);
      str = trim(str);

      for (const auto &validate : validations) {
        validate(str);
      }

      break;
    } catch (const exception &e) {
      cout << e.what() << "\n";
      cin.clear();
    }
  }

  return str;
}