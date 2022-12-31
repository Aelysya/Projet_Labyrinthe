#pragma once
#include "player.h"
namespace coo {
	class leftPlayer : public player
	{
		/**
		 * Tourne la direction actuelle dans le sens antihoraire
		 */
		void changeDirection();
	public:
		leftPlayer(const grid& g);
		int solve();
	};
}
