#include <gtest/gtest.h>
#include <stdexcept>

#include "Utils/Validation/ValidateIndex.hpp"
#include "Exceptions/InvalidIndexException.hpp"
#include "Messages/InvalidIndexMessage.hpp"

TEST(ValidateIndexTest, DoesNotThrowWhenIndexIsValid) {
    // Índices válidos não devem lançar exceção
    EXPECT_NO_THROW(ValidateIndex(0, 5));  // primeiro elemento
    EXPECT_NO_THROW(ValidateIndex(2, 5));  // elemento do meio
    EXPECT_NO_THROW(ValidateIndex(4, 5));  // último elemento
}

TEST(ValidateIndexTest, ThrowsWhenIndexIsEqualToRepositorySize) {
    // Índice igual ao tamanho do repositório é inválido
    EXPECT_THROW(ValidateIndex(5, 5), InvalidIndexException);
}

TEST(ValidateIndexTest, ThrowsWhenIndexIsGreaterThanRepositorySize) {
    // Índice maior que o tamanho também é inválido
    EXPECT_THROW(ValidateIndex(6, 5), InvalidIndexException);
    EXPECT_THROW(ValidateIndex(100, 5), InvalidIndexException);
}

TEST(ValidateIndexTest, ThrowsWhenRepositoryIsEmpty) {
    // Em um repositório vazio, qualquer índice é inválido
    EXPECT_THROW(ValidateIndex(0, 0), InvalidIndexException);
    EXPECT_THROW(ValidateIndex(1, 0), InvalidIndexException);
}

TEST(ValidateIndexTest, CorrectExceptionIsThrown) {
    // Verifica se a exceção correta e a mensagem são as certas
    try {
        ValidateIndex(5, 5);
        FAIL() << "Expected InvalidIndexException to be thrown";
    } catch (const InvalidIndexException& e) {
        EXPECT_STREQ(e.what(), "Hum... esse número não corresponde a nenhum conjunto. Poderia verificar qual o índice correto?");  // Ajuste se a mensagem for diferente
    } catch (...) {
        FAIL() << "Expected InvalidIndexException, but caught a different exception";
    }
}
