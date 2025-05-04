#ifndef COMMAND_HPP
#define COMMAND_HPP

#include <iostream>

#include "Commander/Contexts/CommandContext.hpp"

using std::cout;
using std::string;

class Command {
protected:
  string name;
  string description;

public:
  /**
   * @brief Standard command constructor
   *
   * @param n Command name
   * @param d Command description
   */
  Command(const string &n, const string &d) : name(n), description(d) {}

  /**
   * @brief Returns the command name
   */
  string getName() { return name; };
  /**
   * @brief Returns the command description
   */
  string getDescription() { return description; };

  /**
   * @brief Execution command required by all child classes
   *
   * @param context Context to apply data to be consumed by the command
   */
  virtual void execute(CommandContext *context = nullptr) const = 0;
  /**
   * @brief Destructor command
   */
  virtual ~Command() = default;
};

#endif