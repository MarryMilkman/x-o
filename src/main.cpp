#include "game_lib.h"
#include "Game.hpp"


int main(void)
{
	Game	game;

	while (1)
	{
		game.player_x->step();
		std::cout << "Player X" << std::endl;
		game.dicplay();
		game.player_o->step();
		std::cout << "Player O" << std::endl;
		game.dicplay();
	}
	return (0);
}