#ifndef TOWN_HALL_H
#define TOWN_HALL_H

#include "building.h"

class Town_Hall : public Building {

	public:
		Town_Hall();
		virtual void render_to_array(vector<vector<Colored_Pixel>>&) override;
		virtual void selection_grabbed(Game_State *) override;

};

#endif
