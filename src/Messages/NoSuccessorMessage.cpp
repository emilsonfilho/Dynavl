#include "Messages/NoSuccessorMessage.hpp"

string NoSuccessorMessage(int key) {
  return "Nao ha nenhum elemento que seja sucessor de " + to_string(key);
}
