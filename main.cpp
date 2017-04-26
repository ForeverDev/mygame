#include <iostream>
#include "game.h"

int main(int argc, char** argv) {

	Game_State game;
	
	while (true) {	
		game.render();
		game.draw();	
		game.handle_input();
	}

}
