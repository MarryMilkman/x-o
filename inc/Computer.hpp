#ifndef COMPUTER_HPP
# define COMPUTER_HPP

# include "game_lib.h"
# include "Game.hpp"

class Computer : public Player
{
public:
	Computer(char c, Map *map);
	~Computer();
	
	int						*step() override;
	void					win_phrase() override;
	int						is_human() override;

private:
	int						_check_danger(int *coord);
	int						_check_win(int *coord);
	void					_logic(int *coord);
	int						_defense_mod(int *coord);
	int						_attack_mod(int *coord);

	int						_find_and_replase_all(int arr[], int size, int *coord);
	int						_find_and_replase_for_attack(int arr[], int size, int *coord);
	int						_find_and_replase_without_center(int arr[], int size, int *coord);
	void					_find_possible(int *coord);
	int						_check_line(std::list<t_sector> line, char c);
	int						_check_coord(int const *coord) override;
	int						_check_center(int arr[], int size);

	char					_symbol;
	char					_enemy_symbol;
};
#endif