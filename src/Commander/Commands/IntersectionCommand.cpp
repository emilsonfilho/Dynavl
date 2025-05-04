#include "Commander/Commands/IntersectionCommand.hpp"

IntersectionCommand::IntersectionCommand(const string &name,
                                         const string &description)
    : Command(name, description) {}

void IntersectionCommand::execute(CommandContext *context) const {
  auto *ctx = dynamic_cast<IntersectionCommandContext *>(context);

  if (ctx) {
    Repository repo = ctx->repository;
    int index1 = ctx->index1, index2 = ctx->index2;

    Set *res = repo[index1].set->intersectionSet(*(repo[index2].set));

    repo.emplace_back(res, formatOrigin("intersecao", index1, index2));

    cout << "A intersecao dos conjuntos foi armazenada em " << (repo.size() - 1)
         << '\n';
  }
}
