#include "Commander/Commands/ListCommand.hpp"

ListCommand::ListCommand(const string &name, const string &description)
    : Command(name, description) {}

void ListCommand::execute(CommandContext *context) const {
  auto *ctx = dynamic_cast<ListCommandContext *>(context);

  if (ctx) {
    ConstRepository repo = ctx->repository;

    for (size_t i = 0; i < repo.size(); i++)
      cout << "Conjunto " << i << " - " << repo[i].origin << '\n';
  }
}
