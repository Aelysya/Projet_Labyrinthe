#pragma once
#include "player.h"
namespace coo {
	class yoloPlayer : public player
	{
		/**
		 * Change la direction aléatoirement
		 */
		void changeDirection();
	public:
		yoloPlayer(const grid& g);
		int solve();
	};
}