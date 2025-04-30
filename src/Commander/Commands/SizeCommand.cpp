#include "Commander/Commands/SizeCommand.hpp"

SizeCommand::SizeCommand(const string &name,
                                     const string &description)
    : Command(name, description) {}

void SizeCommand::execute(CommandContext *context) const {
  auto *ctx = dynamic_cast<SizeCommandContext *>(context);

  if (ctx) {
  	const Repository repo = ctx->repository;
  	int index = ctx->index;

    cout << "O tamanho do conjunto " << index << " eh " << ctx->repository[index].set->size() << '\n';
  }
}