#include "Commander/Commands/CreateCommand.hpp"

CreateCommand::CreateCommand(const string &name, const string &description)
    : Command(name, description) {}

void CreateCommand::execute(CommandContext *context) const {
  auto *ctx = dynamic_cast<CreateCommandContext *>(context);

  if (ctx) {
    Set *set = new Set();

    while (!ctx->initialData.empty()) {
      set->insert(ctx->initialData.front());
      ctx->initialData.pop();
    }

    ctx->repository.emplace_back(set, "gerado por linha de comando");
    cout << "Conjunto adicionado com sucesso na posição "
         << ctx->repository.size() - 1 << '\n';
  }
}