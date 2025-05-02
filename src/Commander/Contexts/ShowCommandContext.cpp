#include "Commander/Contexts/ShowCommandContext.hpp"

ShowCommandContext::ShowCommandContext(ConstRepository repository, const queue<int> &indexes)
	: repository(repository), indexes(indexes) {}
