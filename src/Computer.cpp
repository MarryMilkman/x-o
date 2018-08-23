#include "Computer.hpp"

Computer::Computer(char c) : _symbol(c)
{
}

Computer::~Computer()
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