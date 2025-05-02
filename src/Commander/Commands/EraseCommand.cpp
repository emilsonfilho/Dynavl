#include "Commander/Commands/EraseCommand.hpp"

EraseCommand::EraseCommand(const string &name, const string &description)
    : Command(name, description) {}

void EraseCommand::execute(CommandContext *context) const {
  auto *ctx = dynamic_cast<EraseCommandContext *>(context);

  if (ctx) {
    ConstRepository repo = ctx->repository;
    int index = ctx->index, key = ctx->key;

    repo[index].set->erase(key);

    cout << "O valor " << key << " foi removido do conjunto " << index << '\n';
  }
}
