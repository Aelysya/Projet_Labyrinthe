#pragma once
#include "player.h"
namespace coo {
	class leftPlayer : public player
	{
	public:
		leftPlayer(const grid& g);
		bool solve();
	};
}
