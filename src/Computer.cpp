#include "Computer.hpp"

Computer::Computer(char c, t_map & map) : _symbol(c), _map(&map)
{
}

Computer::~Computer()
{
}

void		Computer::step()
{
	this->_do_step(3, 3);
}

void		Computer::_do_step(int x, int y)
{
	this->_map->vect[x - 1][y - 1] = this->_symbol;
}