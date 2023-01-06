#pragma once
#include "player.h"
namespace players {
	class rightIfNotForwardPlayer : public player
	{
		/**
		 * Tourne la direction actuelle dans le sens antihoraire
		 */
		void changeDirection();
	public:
		rightIfNotForwardPlayer(const utility::grid& g);
		int solve();
	};
}