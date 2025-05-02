#include "Commander/Commands/ShowCommand.hpp"

ShowCommand::ShowCommand(const string &name,
                                     const string &description)
    : Command(name, description) {}

void ShowCommand::execute(CommandContext *context) const {
  auto *ctx = dynamic_cast<ShowCommandContext *>(context);

  if (ctx) {
  	ConstRepository repo = ctx->repository;
  	queue<int> setIndexes = ctx->indexes;

    if (setIndexes.empty())
      for (size_t i = 0; i < repo.size(); i++)
        setIndexes.push(i);

  	while (!setIndexes.empty()) {
  		int index = setIndexes.front();

      cout << "Conjunto " << index << '\n';

  		repo[index].set->show();
      cout << '\n';

  		setIndexes.pop();
  	}
  }
}
