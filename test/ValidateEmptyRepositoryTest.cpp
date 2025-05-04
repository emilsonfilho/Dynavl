#include <gtest/gtest.h>
#include <stdexcept>

#include "Utils/Validation/ValidateEmptyRepository.hpp"

TEST(ValidateEmptyRepositoryTest, DoesNotThrowWhenRepositoryNotEmpty) {
  // Quando o repositório tem 1 ou mais elementos, não deve lançar exceção
  EXPECT_NO_THROW(ValidateEmptyRepository(1));
  EXPECT_NO_THROW(ValidateEmptyRepository(5));
  EXPECT_NO_THROW(ValidateEmptyRepository(1000));
}

TEST(ValidateEmptyRepositoryTest, ThrowsWhenRepositoryIsEmpty) {
  // Quando o repositório é vazio (0 elementos), deve lançar exceção
  EXPECT_THROW(ValidateEmptyRepository(0), EmptyRepositoryException);
}

TEST(ValidateEmptyRepositoryTest, CorrectExceptionIsThrown) {
  // Testar se a exceção correta é lançada e com a mensagem correta
  try {
    ValidateEmptyRepository(0);
    FAIL() << "Expected EmptyRepositoryException to be thrown";
  } catch (const EmptyRepositoryException &e) {
    EXPECT_STREQ(e.what(), "Nao foi possivel realizar a operacao. Nenhum "
                           "conjunto foi criado no sistema");
  }
}
