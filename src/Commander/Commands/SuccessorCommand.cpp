#include "Commander/Commands/SuccessorCommand.hpp"

SuccessorCommand::SuccessorCommand(const string &name, const string &description)
    : Command(name, description) {}

void SuccessorCommand::execute(CommandContext *context) const {
  auto *ctx = dynamic_cast<SuccessorCommandContext *>(context);

  if (ctx) {
    ConstRepository repo = ctx->repository;
    int index = ctx->index, key = ctx->key;

    int pred = repo[index].set->successor(key);
    
    cout << "O sucessor de  " << key << " eh "
         << pred << " no conjunto " << index << '\n';
  }
}
