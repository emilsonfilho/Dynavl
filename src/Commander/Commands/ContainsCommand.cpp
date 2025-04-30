
#include "Commander/Commands/ContainsCommand.hpp"

ContainsCommand::ContainsCommand(const string &name,
                                     const string &description)
    : Command(name, description) {}

void ContainsCommand::execute(CommandContext *context) const {
  auto *ctx = dynamic_cast<ContainsCommandContext *>(context);

  if (ctx) {
    int index = ctx->index, key = ctx->key;

    cout << "O conjunto " << index << (ctx->repository[index].set->contains(key) ? " " : " nao ") << "contem o valor " << key << '\n';
  }
}