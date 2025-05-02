#include "Commander/Commands/EmptyCommand.hpp"

EmptyCommand::EmptyCommand(const string &name,
                                     const string &description)
    : Command(name, description) {}

void EmptyCommand::execute(CommandContext *context) const {
  auto *ctx = dynamic_cast<EmptyCommandContext *>(context);

  if (ctx) {
  	ConstRepository repo = ctx->repository;
  	int index = ctx->index;

    cout << "O conjunto " << index << (repo[index].set->empty() ? " " : " nao ") << "esta vazio." << '\n';
  }
}
