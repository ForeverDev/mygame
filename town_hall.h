#ifndef TOWN_HALL_H
#define TOWN_HALL_H

#include "building.h"
#include "game.h"

class Town_Hall : public Building {

	public:
		Town_Hall();
		virtual void selection_grabbed(Game_State *) override;

};

#endif
