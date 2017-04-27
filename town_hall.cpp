#include <iostream>
#include "town_hall.h"

Town_Hall::Town_Hall() {
	radius_x = 3;
	radius_y = 3;
	color = const_color::YELLOW;
}

void
Town_Hall::selection_grabbed(Game_State* state) {

	state->reset_screen();

}
