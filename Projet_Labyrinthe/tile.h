#pragma once

namespace coo {
	class tile
	{
	public:
		tile();
		tile(const int& x, const int& y);
		~tile();

		void print() const;

	private:
		int positionX;
		int positionY;
	};
}

