#include "town_hall.h"
#include "user.h"

User::User(int x, int y) {

	auto hall = make_unique<Town_Hall>();
	hall->x = x;
	hall->y = y;
	town_hall = hall.get();
	buildings.push_back(move(hall));


}
