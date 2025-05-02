#include "Commander/Commands/MaximumCommand.hpp"

MaximumCommand::MaximumCommand(const string &name, const string &description)
    : Command(name, description) {}

void MaximumCommand::execute(CommandContext *context) const {
  auto *ctx = dynamic_cast<MaximumCommandContext *>(context);

  if (ctx) {
    ConstRepository repo = ctx->repository;
    int index = ctx->index;

    cout << "O maior elemento do conjunto " << index << " eh "
         << repo[index].set->maximum() << '\n';
  }
}
