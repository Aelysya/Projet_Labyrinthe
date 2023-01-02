#pragma once
#include "player.h"
namespace coo {
	class leftIfNotForwardPlayer : public player
	{
		/**
		 * Tourne la direction actuelle dans le sens antihoraire
		 */
		void changeDirection();
	public:
		leftIfNotForwardPlayer(const grid& g);
		int solve();
	};
}
