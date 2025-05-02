#include "Commander/Commands/MinimumCommand.hpp"

MinimumCommand::MinimumCommand(const string &name, const string &description)
    : Command(name, description) {}

void MinimumCommand::execute(CommandContext *context) const {
  auto *ctx = dynamic_cast<MinimumCommandContext *>(context);

  if (ctx) {
    ConstRepository repo = ctx->repository;
    int index = ctx->index;

    cout << "O menor elemento do conjunto " << index << " eh "
         << repo[index].set->minimum() << '\n';
  }
}
