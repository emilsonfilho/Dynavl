#include "Commander/Contexts/ShowCommandContext.hpp"

ShowCommandContext::ShowCommandContext(const Repository repository, const queue<int> &indexes)
	: repository(repository), indexes(indexes) {}