#include "Commander/Commands/ClearCommand.hpp"

ClearCommand::ClearCommand(const string &name,
                                     const string &description)
    : Command(name, description) {}

void ClearCommand::execute(CommandContext *context) const {
  auto *ctx = dynamic_cast<ClearCommandContext *>(context);

  if (ctx) {
  	Repository repo = ctx->repository;
  	int index = ctx->index;

  	repo[index].set->clear();

    cout << "O conjunto " << index << " foi limpo com suceso." << '\n';
  }
}