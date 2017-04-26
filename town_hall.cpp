#include <iostream>
#include "math.h"
#include "town_hall.h"
#include "color.h"

Town_Hall::Town_Hall() {
	radius_x = 3;
	radius_y = 3;
	color = Color_Pair(FORE_YELLOW, BACK_BLACK);
}

void
Town_Hall::render_to_array(vector<vector<Colored_Pixel>>& array) {
	
	for (int i = 0; i < radius_x; i++) {
		for (int j = 0; j < radius_y; j++) {
			safe_char_put(array, x - radius_x/2 + i, y - radius_y/2 + j, color, '#');
		}
	}	
	
	safe_string_put(array, x, y, const_color::WHITE, std::to_string(selection_index));	

}

void
Town_Hall::selection_grabbed(Game_State* state) {

	state->reset_screen();
	safe_string_put(state->screen, 0, 0, const_color::WHITE, "hello!");

}
