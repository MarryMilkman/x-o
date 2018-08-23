#include "game_lib.h"
#include "Game.hpp"


int main(void)
{
	Game	game;

	while (1)
	{
		game.player_x->step();
		game.dicplay();
		game.player_o->step();
		game.dicplay();
		exit(0);
	}
	return (0);
}