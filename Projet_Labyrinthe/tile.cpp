#include "tile.h"
#include <iostream>

coo::tile::tile() : positionX(-1), positionY(-1)
{
}

coo::tile::tile(const int& x, const int& y) : positionX(x), positionY(y)
{
}

coo::tile::~tile()
{
}

void coo::tile::print() const
{
	std::cout << positionX << " " << positionY << std::endl;
}
