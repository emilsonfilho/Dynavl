#include <gtest/gtest.h>
#include <stdexcept>
#include <string>

#include "Exceptions/InvalidNumberInputException.hpp"
#include "Messages/InvalidNumberInputMessage.hpp"
#include "Utils/Validation/ValidateOnlyIntegers.hpp"

using std::string;

// Função a ser testada
void ValidateOnlyIntegers(const string& str);

// Testa a validação de inteiros válidos
TEST(ValidateOnlyIntegersTest, ValidInteger) {
    // Testa números inteiros positivos
    EXPECT_NO_THROW(ValidateOnlyIntegers("123"));

    // Testa números inteiros negativos
    EXPECT_NO_THROW(ValidateOnlyIntegers("-123"));

    // Testa número zero
    EXPECT_NO_THROW(ValidateOnlyIntegers("0"));
}

// Testa entradas inválidas que devem lançar exceção
TEST(ValidateOnlyIntegersTest, InvalidInteger) {
    // Testa string com letras
    EXPECT_THROW(ValidateOnlyIntegers("123abc"), InvalidNumberInputException);

    // Testa string com espaços
    EXPECT_NO_THROW(ValidateOnlyIntegers("123 45"));

    // Testa string com símbolos
    EXPECT_THROW(ValidateOnlyIntegers("123$45"), InvalidNumberInputException);

    // Testa string com ponto decimal
    EXPECT_THROW(ValidateOnlyIntegers("123.45"), InvalidNumberInputException);

    // Testa string vazia
    EXPECT_NO_THROW(ValidateOnlyIntegers(""));

    // Testa string com um sinal sem número (ex: "-")
    EXPECT_THROW(ValidateOnlyIntegers("-"), InvalidNumberInputException);
}

// Testa casos de números negativos
TEST(ValidateOnlyIntegersTest, NegativeInteger) {
    // Testa número negativo válido
    EXPECT_NO_THROW(ValidateOnlyIntegers("-999"));

    // Testa número negativo com espaço no meio (inválido)
    EXPECT_THROW(ValidateOnlyIntegers("- 999"), InvalidNumberInputException);

    // Testa número negativo com letras (inválido)
    EXPECT_THROW(ValidateOnlyIntegers("-abc"), InvalidNumberInputException);

    // Testa número negativo com símbolos (inválido)
    EXPECT_THROW(ValidateOnlyIntegers("-123$"), InvalidNumberInputException);
}

// Testa casos de entradas com caracteres não numéricos
TEST(ValidateOnlyIntegersTest, NonNumericInput) {
    // Testa entrada com letras
    EXPECT_THROW(ValidateOnlyIntegers("hello"), InvalidNumberInputException);

    // Testa entrada com caracteres especiais
    EXPECT_THROW(ValidateOnlyIntegers("123!@#"), InvalidNumberInputException);
}

// Testa strings que começam com números, mas têm caracteres não numéricos no final
TEST(ValidateOnlyIntegersTest, ValidPrefixInvalidSuffix) {
    // Testa que a string começa com números mas tem caracteres não numéricos no final
    EXPECT_THROW(ValidateOnlyIntegers("123abc"), InvalidNumberInputException);
}

// Testa a exceção correta sendo lançada
TEST(ValidateOnlyIntegersTest, ThrowsExceptionWithInvalidInput) {
    try {
        ValidateOnlyIntegers("123abc");
        FAIL() << "Expected InvalidNumberInputException to be thrown";
    } catch (const InvalidNumberInputException& e) {
        EXPECT_STREQ(e.what(), "Oops! Parece que você digitou algo além de números. Tente novamente, por favor.");
    } catch (...) {
        FAIL() << "Expected InvalidNumberInputException, but caught a different exception";
    }
}
