#pragma once
#include "player.h"
namespace coo {
	class rightIfNotForwardPlayer : public player
	{
		/**
		 * Tourne la direction actuelle dans le sens antihoraire
		 */
		void changeDirection();
	public:
		rightIfNotForwardPlayer(const grid& g);
		int solve();
	};
}