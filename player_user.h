#ifndef PLAYER_USER
#define PLAYER_USER

#include "user.h"
#include "game.h"

class Player_User : public User {

	private:

	public:
		Player_User(): User(0, 0) {}
		Player_User(int x, int y): User(x, y) {}

		void make_move(Game_State *) override;

};

#endif
