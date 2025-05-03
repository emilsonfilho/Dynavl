#include "Messages/ValueNotFoundMessage.hpp"

string ValueNotFoundMessage(int key) {
  return "Valor " + to_string(key) + " nao encontrado.";
}
