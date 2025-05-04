#include <gtest/gtest.h>

#include "Utils/Tools/Trim.hpp"

TEST(TrimTest, TrimEmptyString) {
  // Testa uma string vazia
  EXPECT_EQ(trim(""), "");
}

TEST(TrimTest, TrimStringWithOnlySpaces) {
  // Testa uma string que contém apenas espaços
  EXPECT_EQ(trim("     "), "");
}

TEST(TrimTest, TrimStringWithLeadingSpaces) {
  // Testa uma string com espaços no início
  EXPECT_EQ(trim("   Hello World"), "Hello World");
}

TEST(TrimTest, TrimStringWithTrailingSpaces) {
  // Testa uma string com espaços no final
  EXPECT_EQ(trim("Hello World   "), "Hello World");
}

TEST(TrimTest, TrimStringWithLeadingAndTrailingSpaces) {
  // Testa uma string com espaços no início e no final
  EXPECT_EQ(trim("   Hello World   "), "Hello World");
}

TEST(TrimTest, TrimStringWithNoSpaces) {
  // Testa uma string sem espaços
  EXPECT_EQ(trim("HelloWorld"), "HelloWorld");
}

TEST(TrimTest, TrimStringWithSpacesAroundTabsAndNewlines) {
  // Testa uma string com espaços, tabs e quebras de linha
  EXPECT_EQ(trim("\t  \n  Hello\n\t "), "Hello");
}

TEST(TrimTest, TrimStringWithSpacesOnlyAtTheEdges) {
  // Testa string com espaços somente nas extremidades
  EXPECT_EQ(trim("   "), "");
}

TEST(TrimTest, TrimStringWithMultipleSpacesInTheMiddle) {
  // Testa string com múltiplos espaços no meio
  EXPECT_EQ(trim("   Hello    World   "), "Hello World");
}

TEST(TrimTest, TrimStringWithSingleCharacter) {
  // Testa uma string com um único caractere
  EXPECT_EQ(trim(" A "), "A");
}

TEST(TrimTest, TrimStringWithTabsOnly) {
  // Testa uma string com apenas tabs no início e final
  EXPECT_EQ(trim("\t\tHello\t"), "Hello");
}

TEST(TrimTest, TrimStringWithCarriageReturn) {
  // Testa uma string com retorno de carro no início e final
  EXPECT_EQ(trim("\rHello World\r"), "Hello World");
}

TEST(TrimTest, TrimStringWithMixedWhitespace) {
  // Testa string com caracteres de espaços misturados (espaços, tabs, novas
  // linhas)
  EXPECT_EQ(trim("\t \n  Hello World  \r "), "Hello World");
}

TEST(TrimTest, TrimStringContainingNonWhitespaceCharacters) {
  // Testa se o comportamento está correto quando a string contém outros
  // caracteres não espaço
  EXPECT_EQ(trim(" \t Test 123 \n "), "Test 123");
}
