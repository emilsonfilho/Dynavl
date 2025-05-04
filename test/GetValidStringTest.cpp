#include <functional>
#include <gtest/gtest.h>
#include <iostream>
#include <sstream>
#include <string>

#include "Utils/Tools/GetValidString.hpp"

using std::cin;
using std::invalid_argument;
using std::string;
using std::stringstream;

// Helper to simulate user input for testing purposes
static void simulateInput(stringstream &ss, const string &input) {
  ss.str(input);
  ss.clear();
  cin.rdbuf(ss.rdbuf());
}

// Simple validators
void nonEmptyValidator(const string &str) {
  if (str.empty()) {
    throw invalid_argument("Input cannot be empty");
  }
}

void startsWithCapitalValidator(const string &str) {
  if (!str.empty() && !isupper(str[0])) {
    throw invalid_argument("Input must start with a capital letter");
  }
}

TEST(GetValidStringTest, ValidStringWithOneValidator) {
  // Test for valid string input
  stringstream input;
  input.str("Hello World\n"); // Simulate input from the user
  simulateInput(input, "Hello World");

  auto validators = [](const string &str) { nonEmptyValidator(str); };

  string result = getValidString("Enter a string: ", validators);

  EXPECT_EQ(result, "Hello World");
}

TEST(GetValidStringTest, InvalidStringWithOneValidator) {
  // Test for invalid empty string input
  stringstream input;
  input.str("\nHello World\n"); // Simulate invalid input followed by valid one
  simulateInput(input, "\nHello World");

  auto validators = [](const string &str) { nonEmptyValidator(str); };

  string result = getValidString("Enter a non-empty string: ", validators);

  EXPECT_EQ(result, "Hello World");
}

TEST(GetValidStringTest, ValidStringWithMultipleValidators) {
  // Test for valid string that satisfies multiple validators
  stringstream input;
  input.str("Hello World\n"); // Simulate input from the user
  simulateInput(input, "Hello World");

  auto validators = [](const string &str) {
    nonEmptyValidator(str);
    startsWithCapitalValidator(str);
  };

  string result = getValidString("Enter a valid string: ", validators);

  EXPECT_EQ(result, "Hello World");
}

TEST(GetValidStringTest, InvalidStringWithMultipleValidators) {
  // Test for invalid string input that fails startsWithCapitalValidator
  stringstream input;
  input.str("hello world\nHello World\n"); // Simulate invalid input followed by
                                           // valid one
  simulateInput(input, "hello world\nHello World");

  auto validators = [](const string &str) {
    nonEmptyValidator(str);
    startsWithCapitalValidator(str);
  };

  string result = getValidString(
      "Enter a string starting with a capital letter: ", validators);

  EXPECT_EQ(result, "Hello World");
}

TEST(GetValidStringTest, InvalidStringWithMultipleValidatorsFailsFirst) {
  // Test for invalid string input that fails the nonEmptyValidator
  stringstream input;
  input.str("\nhello world\nHello World\n"); // Simulate invalid input followed
                                             // by valid one
  simulateInput(input, "\nhello world\nHello World");

  auto validators = [](const string &str) {
    nonEmptyValidator(str);
    startsWithCapitalValidator(str);
  };

  string result = getValidString(
      "Enter a non-empty string starting with a capital letter: ", validators);

  EXPECT_EQ(result, "Hello World");
}

TEST(GetValidStringTest, InputValidationWithMultipleFailures) {
  // Test when multiple invalid inputs are provided
  stringstream input;
  input.str("\n\nhello\nHello World\n"); // Invalid inputs followed by valid one
  simulateInput(input, "\n\nhello\nHello World");

  auto validators = [](const string &str) {
    nonEmptyValidator(str);
    startsWithCapitalValidator(str);
  };

  string result = getValidString("Enter a valid string: ", validators);

  EXPECT_EQ(result, "Hello World");
}

TEST(GetValidStringTest, DoesNotEnterInfiniteLoop) {
  // Test when there is no infinite loop and returns valid string after multiple
  // invalid attempts
  stringstream input;
  input.str("\n\nhello\nHello World\n"); // Invalid inputs followed by valid one
  simulateInput(input, "\n\nhello\nHello World");

  auto validators = [](const string &str) {
    nonEmptyValidator(str);
    startsWithCapitalValidator(str);
  };

  string result = getValidString("Enter a valid string: ", validators);

  EXPECT_EQ(result, "Hello World");
}
