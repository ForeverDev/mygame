#ifndef BUILDING_H
#define BUILDING_H

#include "node.h"
#include "color.h"

class Game_State;

class Building : public Node {

	public:
		int current_xp = 0;

		virtual void selection_grabbed(Game_State *) = 0;

	protected:
		int level = 1;
		int radius_x = 3;
		int radius_y = 3;
		Color_Pair color;

};

#endif
