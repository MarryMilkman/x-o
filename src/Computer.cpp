#include "Computer.hpp"

Computer::Computer(char c, Map *map) : _symbol(c)
{
	this->_enemy_symbol = (this->_symbol == 'x') ? 'o' : 'x';
	this->_map = map;
}

Computer::~Computer()
{
}

void	Computer::win_phrase()
{
	std::cout << "It was easy\n";
}

int		*Computer::step()
{
	int	*coord = new int[2];

	this->_logic(coord);
	return (coord);
}

int		Computer::_check_coord(int const *coord)
{					
	if (this->_map->arr_str[coord[0]][coord[1]] != '.')
		return (0);
	return (1);
}

int		Computer::is_human()
{
	return (0);
}

// Algoritm ----------------------------------------------

void	Computer::_logic(int *coord)
{
	if (this->_check_win(coord))
		return ;
	if (this->_check_danger(coord))
		return ;
	if (this->_symbol == 'x' && this->_attack_mod(coord))
		return ;
	else if (this->_defense_mod(coord))
		return ;
	this->_find_possible(coord);
}

int		Computer::_check_win(int *coord)
{
	std::list<t_sector>::iterator	it;
	int								i;
	int								win_count;
	char							c;
	int								change;

	i = 0;
	c = 0;
	while (i < 8)
	{
		change = 0;
		win_count = 0;
		it = this->_map->line[i].begin();
		while (it != this->_map->line[i].end())
		{
			c = *(it->symbol);
			if (c == this->_symbol)
				win_count++;
			if (c == '.')
			{
				change = 1;
				coord[0] = it->coord[0];
				coord[1] = it->coord[1];
			}
			it++;
		}
		if (win_count >= 2 && change)
			return (1);
		i++;
	}
	return (0);
}

int		Computer::_check_danger(int *coord)
{
	std::list<t_sector>::iterator	it;
	int								i;
	int								denger_count;
	char							c;
	int								change;

	i = 0;
	c = 0;
	while (i < 8)
	{
		change = 0;
		denger_count = 0;
		it = this->_map->line[i].begin();
		while (it != this->_map->line[i].end())
		{
			c = *(it->symbol);
			if (c == this->_enemy_symbol)
				denger_count++;
			if (c == '.')
			{
				change = 1;
				coord[0] = it->coord[0];
				coord[1] = it->coord[1];
			}
			it++;
		}
		if (denger_count >= 2 && change)
			return (1);
		i++;
	}
	return (0);
}

int		Computer::_attack_mod(int *coord)
{
	int								i;
	std::list<t_sector>				line;
	std::list<t_sector>::iterator	it;
	int								ret_result;

	ret_result = 0;
	i = -1;
	while (++i < 4)
	{
		if (i == 1 || i == 2)
			continue;
		line = this->_map->line[i];
		if (this->_check_line(line, this->_enemy_symbol))
			continue;
		int		arr[] = {i};
		if (this->_find_and_replase_for_attack(arr, 1, coord))
			ret_result = 1;
	}
	it = this->_map->line[6].begin();
	it++;
	if (!ret_result || *(it->symbol) == this->_enemy_symbol)
	{
		it++;
		if (*(it->symbol) == '.')
		{
			coord[0] = it->coord[0];
			coord[1] = it->coord[1];
			return (1);
		}
	}
	return (ret_result);
}

int		Computer::_defense_mod(int *coord)
{
	std::list<t_sector>				line;
	std::list<t_sector>::iterator	it;

	it = this->_map->line[6].begin();
	it++;
	if (*(it->symbol) == '.')
	{
		coord[0] = it->coord[0];
		coord[1] = it->coord[1];
		return (1);
	}
	int		arr[] = {0, 2, 3, 5};
	if (*(it->symbol) == 'o' && !this->_check_center(arr, 4))
	{
		int		arr[] = {1, 4};
		if (this->_find_and_replase_without_center(arr, 2, coord))
			return (1);
	}
	else
	{
		int		arr[] = {6, 7};
		if (this->_find_and_replase_without_center(arr, 2, coord))
			return (1);
	}
	return (0);
}

void	Computer::_find_possible(int *coord)
{
	int	i;
	int	j;
	int	arr[8] = {0, 1, 2, 3, 4, 5, 6, 7};

	if (this->_find_and_replase_all(arr, 8, coord))
		return ;
	i = -1;
	while (++i < 3)
	{
		j = -1;
		while (++j < 3)
			if (this->_map->arr_str[i][j] == '.')
			{
				coord[0] = i;
				coord[1] = j;
				return;
			}
	}
}

int		Computer::_find_and_replase_for_attack(int arr[], int size, int *coord)
{
	std::list<t_sector>				line;
	std::list<t_sector>::iterator	it;
	int								danger_count;
	int								change;
	int								i;

	while (size--)
	{
		line = this->_map->line[*arr++];
		it = line.begin();
		danger_count = 0;
		change = 0;
		i = 0;
		while (it != line.end())
		{
			if (i++ == 1)
			{
				it++;
				continue ;
			}
			if (*(it->symbol) == this->_enemy_symbol)
				danger_count++;
			if (*(it->symbol) == '.' && !change)
			{
				change = 1;
				coord[0] = it->coord[0];
				coord[1] = it->coord[1];
			}
			it++;
		}
		if (change && !danger_count)
			return (1);
	}
	return (0);
}

int		Computer::_find_and_replase_without_center(int arr[], int size, int *coord)
{
	std::list<t_sector>				line;
	std::list<t_sector>::iterator	it;
	int								danger_count;
	int								change;
	int								i;

	while (size--)
	{
		line = this->_map->line[*arr++];
		it = line.begin();
		danger_count = 0;
		change = 0;
		i = 0;
		while (it != line.end())
		{
			if (i++ == 1)
			{
				it++;
				continue ;
			}
			if (*(it->symbol) != '.')
				danger_count++;
			if (*(it->symbol) == '.' && !change)
			{
				change = 1;
				coord[0] = it->coord[0];
				coord[1] = it->coord[1];
			}
			it++;
		}
		if (change && !danger_count)
			return (1);
	}
	return (0);
}

int		Computer::_find_and_replase_all(int arr[], int size, int *coord)
{
	std::list<t_sector>				line;
	std::list<t_sector>::iterator	it;
	int								danger_count;
	int								win_count;
	int								change;

	while (size--)
	{
		line = this->_map->line[*arr++];
		it = line.begin();
		danger_count = 0;
		win_count = 0;
		change = 0;
		while (it != line.end())
		{
			if (*(it->symbol) == this->_enemy_symbol)
				danger_count++;
			if (*(it->symbol) == this->_symbol)
				win_count++;
			if (*(it->symbol) == '.' && !change)
			{
				change = 1;
				coord[0] = it->coord[0];
				coord[1] = it->coord[1];
			}
			it++;
		}
		if (change && !danger_count && win_count)
			return (1);
	}
	return (0);
}

int		Computer::_check_line(std::list<t_sector> line, char c)
{
	std::list<t_sector>::iterator	it;

	it = line.begin();
	while (it != line.end())
	{
		if (*(it->symbol) == c)
			return (1);
		it++;
	}
	return (0);
}

int		Computer::_check_center(int arr[], int size)
{
	std::list<t_sector>				line;
	std::list<t_sector>::iterator	it;
	int								i;
	int								count;

	count = 0;
	while (size--)
	{
		line = this->_map->line[*arr++];
		it = line.begin();
		i = 0;
		while (it != line.end())
		{
			if (i++ == 1 && *(it->symbol) == this->_enemy_symbol)
				count++;
			it++;
		}
		if (count == 2)
			return (1);
	}
	return (0);
}