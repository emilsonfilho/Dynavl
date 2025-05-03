#include "Commander/Commands/PredecessorCommand.hpp"

PredecessorCommand::PredecessorCommand(const string &name, const string &description)
    : Command(name, description) {}

void PredecessorCommand::execute(CommandContext *context) const {
  auto *ctx = dynamic_cast<PredecessorCommandContext *>(context);

  if (ctx) {
    ConstRepository repo = ctx->repository;
    int index = ctx->index, key = ctx->key;

    int pred = repo[index].set->predecessor(key);
    
    cout << "O antecessor de  " << key << " eh "
         << pred << " no conjunto " << index << '\n';
  }
}
