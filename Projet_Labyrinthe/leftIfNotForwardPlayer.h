#pragma once
#include "player.h"
namespace players {
	class leftIfNotForwardPlayer : public player
	{
		/**
		 * Tourne la direction actuelle dans le sens antihoraire
		 */
		void changeDirection();
	public:
		leftIfNotForwardPlayer(const utility::grid& g);
		int solve();
	};
}
