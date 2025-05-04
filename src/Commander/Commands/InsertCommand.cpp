#include "Commander/Commands/InsertCommand.hpp"

InsertCommand::InsertCommand(const string &name, const string &description)
    : Command(name, description) {}

void InsertCommand::execute(CommandContext *context) const {
  auto *ctx = dynamic_cast<InsertCommandContext *>(context);

  if (ctx) {
    ConstRepository repo = ctx->repository;
    int index = ctx->index, value = ctx->value;

    repo[index].set->insert(value);

    cout << "Elemento " << value << " adicionado no conjunto " << index << '\n';
  }
}
