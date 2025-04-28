#include "Commander/Commands/ShowCommand.hpp"

ShowCommand::ShowCommand(const string &name,
                                     const string &description)
    : Command(name, description) {}

void ShowCommand::execute(CommandContext *context) const {
  auto *ctx = dynamic_cast<ShowCommandContext *>(context);

  if (ctx) {
  	const Repository repo = ctx->repository;
  	queue<int> setIndexes = ctx->indexes;

  	while (!setIndexes.empty()) {
  		int index = setIndexes.front();

  		repo[index].set->show();

  		setIndexes.pop();
  	}
  }
}