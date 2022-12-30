#pragma once
#include "player.h"
namespace coo {
	class yoloPlayer : public player
	{
		/**
		 * Tourne la direction actuelle dans le sens antihoraire
		 */
		void changeDirection();
	public:
		yoloPlayer(const grid& g);
		bool solve();
	};
}