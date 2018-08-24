#ifndef MAP_HPP
# define MAP_HPP

# include <game_lib.h>

typedef struct					s_sector
{
	int							coord[2];
	char						*symbol;
}								t_sector;

class Map
{
public:
	Map();
	~Map();

	std::vector<char *>					arr_str;
	std::vector<std::list<t_sector>>	line;
private:
	void							_create_line();
};

#endif