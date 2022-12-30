#pragma once
#include "player.h"
namespace coo {
	class rightPlayer : public player
	{
	public:
		rightPlayer(const grid& g);
		bool solve();
	};
}