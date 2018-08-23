#include "Human.hpp"

Human::Human(char c) : _symbol(c)
{
}

Human::~Human()
{
}

void		step()
{
	this->_do_step(1, 2);
}

void		_do_step(int x, int y)
{
	this->_map[x][y] = this->_symbol;
}