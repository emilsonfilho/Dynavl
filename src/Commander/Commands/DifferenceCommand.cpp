#include "Commander/Commands/DifferenceCommand.hpp"

DifferenceCommand::DifferenceCommand(const string &name,
                                     const string &description)
    : Command(name, description) {}

void DifferenceCommand::execute(CommandContext *context) const {
  auto *ctx = dynamic_cast<DifferenceCommandContext *>(context);

  if (ctx) {
    Repository repo = ctx->repository;
    int index1 = ctx->index1, index2 = ctx->index2;

    Set *res = repo[index1].set->differenceSet(*(repo[index2].set));

    repo.emplace_back(res, formatOrigin("diferenca", index1, index2));

    cout << "A diferenca dos conjuntos foi armazenada em " << (repo.size() - 1)
         << '\n';
  }
}
