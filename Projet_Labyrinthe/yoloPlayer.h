#pragma once
#include "player.h"
namespace coo {
	class yoloPlayer : public player
	{
		/**
		 * Change la direction al�atoirement
		 */
		void changeDirection();
	public:
		yoloPlayer(const grid& g);
		int solve();
	};
}