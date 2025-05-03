#include "Messages/NoPredecessorMessage.hpp"

string NoPredecessorMessage(int key) {
  return "Nao ha nenhum elemento que seja antecessor de " + to_string(key);
}
