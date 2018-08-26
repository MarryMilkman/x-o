#include <Map.hpp>

Map::Map()
{
	int					i;
	std::vector<char *>	v(3);

	this->arr_str = v;
	i = -1;
	while (++i < 3)
	{
		(this->arr_str)[i] = new char[4];
		this->arr_str[i][0] = '.';
		this->arr_str[i][1] = '.';
		this->arr_str[i][2] = '.';
		this->arr_str[i][3] = 0;
	}
	this->_create_line();
}

Map::Map(Map const & ref)
{
	*this = ref;
}

Map::~Map()
{
	int	i;

	std::cout << "Map des dell\n";
	i = -1;
	while (++i < 3)
		delete[] this->arr_str[i];
}

void		Map::_create_line()
{
	int									i;
	int									x;
	int									y;
	t_sector							sector;
	std::vector<std::list<t_sector>>	v(8);

	this->line = v;
	i = 0;
	while (i < 6)
	{
		x = i <= 2 ? i : 0;
		y = i > 2 ? i - 3 : 0;
		while (x < 3 && y < 3)
		{
			
			sector.coord[0] = x;
			sector.coord[1] = y;
			sector.symbol = &(this->arr_str[x][y]);
			this->line[i].push_back(sector);
			i <= 2 ? y++ : x++;
		}
		i++;
	}
	while (i < 8)
	{
		i == 6 ? x = 0 : x = 2;
		y = 0;
		while (x >= 0 && x < 3)
		{
			sector.coord[0] = x;
			sector.coord[1] = y;
			sector.symbol = &(this->arr_str[x][y]);
			this->line[i].push_back(sector);
			i == 6 ? x++ : x--;
			y++;
		}
		i++;
	}
}

Map		& Map::operator=(Map const & ref)
{
	this->arr_str = ref.arr_str;
	this->line = ref.line;
	return (*this);
}