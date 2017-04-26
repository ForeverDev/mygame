#ifndef BUILDING_H
#define BUILDING_H

#include "game.h"
#include "node.h"
#include "color.h"

class Building : public Node {

	public:
		int current_xp = 0;
		int selection_index;

		virtual void render_to_array(vector<vector<Colored_Pixel>>&) override = 0;	
		virtual void selection_grabbed(Game_State *) = 0;

	protected:
		int level = 1;
		int radius_x = 3;
		int radius_y = 3;
		Color_Pair color;

};

#endif
