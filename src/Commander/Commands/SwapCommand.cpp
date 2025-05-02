#include "Commander/Commands/SwapCommand.hpp"

SwapCommand::SwapCommand(const string& name, const string& description)
    : Command(name, description) {}

void SwapCommand::execute(CommandContext *context) const {
    auto *ctx = dynamic_cast<SwapCommandContext *>(context);
    
    if (ctx) {
        ConstRepository repo = ctx->repository;
        int index1 = ctx->index1, index2 = ctx->index2;
        
        repo[index1].set->swap(*(repo[index2].set));
        
        cout << "O conjunto " << index1 << " foi trocado com o conjunto " << index2 << '\n';
    }
}   
