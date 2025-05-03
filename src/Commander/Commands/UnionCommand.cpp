#include "Commander/Commands/UnionCommand.hpp"

UnionCommand::UnionCommand(const string& name, const string& description)
    : Command(name, description) {}

void UnionCommand::execute(CommandContext *context) const {
    auto *ctx = dynamic_cast<UnionCommandContext *>(context);
    
    if (ctx) {
        Repository repo = ctx->repository;
        int index1 = ctx->index1, index2 = ctx->index2;
        
        Set res = repo[index1].set->unionSet(*(repo[index2].set));

        repo.emplace_back(res, formatOrigin("uniao", index1, index2));
        
        cout << "A uniao dos conjuntos foi armazenada em " << repo[repo.size() - 1]  <<  '\n';
    }
}   
