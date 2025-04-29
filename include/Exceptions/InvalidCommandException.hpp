#ifndef INVALID_COLUMN_EXCEPTION_HPP
#define INVALID_COLUMN_EXCEPTION_HPP

#include <stdexcept>

using std::runtime_error;
using std::string;

class InvalidCommandException : public runtime_error {
public:
  /**
   * @brief Cria uma exceção de coluna inválida
   *
   * @param message Mensagem a ser exibida
   */
  explicit InvalidCommandException(const string &message);
};

#endif