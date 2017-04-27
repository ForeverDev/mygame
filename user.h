#ifndef USER_H
#define USER_H

#include <vector>
#include <memory>
#include "color.h"
#include "building.h"

using namespace std;

class Game_State;

class User {
	
	private:

	public:
		User() : User(0, 0) {}
		User(int, int);
		virtual void make_move(Game_State *) = 0;

		int funds;
		vector<unique_ptr<Building>> buildings;
		Building* town_hall;

};

#endif
