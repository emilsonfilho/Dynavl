#include <functional>
#include <gtest/gtest.h>
#include <iostream>
#include <sstream>
#include <vector>

#include "Exceptions/InvalidArgumentException.hpp"
#include "Messages/InvalidArgumentForNumberMessage.hpp"
#include "Utils/Tools/GetValidNumber.hpp"

using std::cin;
using std::string;
using std::stringstream;

// Helper to simulate user input for testing purposes
static void simulateInput(stringstream &ss, const string &input) {
  ss.str(input);
  ss.clear();
  cin.rdbuf(ss.rdbuf());
}

// A simple validator that ensures the number is positive
void positiveValidator(int number) {
  if (number <= 0) {
    throw InvalidArgumentException(InvalidArgumentForNumberMessage());
  }
}

// A simple validator that ensures the number is less than 100
void lessThan100Validator(int number) {
  if (number >= 100) {
    throw InvalidArgumentException(InvalidArgumentForNumberMessage());
  }
}

TEST(GetValidNumberTest, ValidNumberWithOneValidator) {
  // Test for valid positive number input
  stringstream input;
  input.str("42\n"); // Simulate input from the user
  simulateInput(input, "42");

  IntValidator validators = positiveValidator;

  int result = getValidNumber("Enter a positive number: ", validators);

  EXPECT_EQ(result, 42);
}

TEST(GetValidNumberTest, InvalidThenValid) {
  // Simula: primeiro -5 (inválido), depois 42 (válido)
  stringstream input("-5\n42\n");
  cin.rdbuf(input.rdbuf());

  IntValidator validators = positiveValidator;

  int result = getValidNumber("Enter a positive number: ", validators);
  EXPECT_EQ(result, 42);
}

TEST(GetValidNumberTest, ValidNumberWithMultipleValidators) {
  // Test for valid number that satisfies multiple validators
  stringstream input;
  input.str("42\n"); // Simulate input from the user
  simulateInput(input, "42");

  IntValidator validators = [](int number) {
    positiveValidator(number);
    lessThan100Validator(number);
  };

  int result =
      getValidNumber("Enter a positive number less than 100: ", validators);

  EXPECT_EQ(result, 42);
}

TEST(GetValidNumberTest, InvalidNumberWithMultipleValidators) {
  // Test for invalid number that fails the "less than 100" validator
  stringstream input;
  input.str("150\n42\n"); // Simulate invalid input followed by valid one
  simulateInput(input, "150\n42");

  IntValidator validators = [](int number) {
    positiveValidator(number);
    lessThan100Validator(number);
  };

  int result =
      getValidNumber("Enter a positive number less than 100: ", validators);
  EXPECT_EQ(result, 42);
}

TEST(GetValidNumberTest, InputValidationWithMultipleFailures) {
  // Test when multiple invalid inputs are provided
  stringstream input;
  input.str("-1\n0\n105\n42\n"); // Invalid inputs followed by valid one
  simulateInput(input, "-1\n0\n105\n42");

  IntValidator validators = [](int number) {
    positiveValidator(number);
    lessThan100Validator(number);
  };

  int result =
      getValidNumber("Enter a positive number less than 100: ", validators);

  EXPECT_EQ(result, 42);
}