#pragma once
#include "player.h"
namespace coo {
	class rightPlayer : public player 
	{
		/**
		 * Tourne la direction actuelle dans le sens horaire
		 */
		void changeDirection();
	public:
		rightPlayer(const grid& g);
		int solve();
	};
}