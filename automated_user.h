#ifndef AUTOMATED_USER
#define AUTOMATED_USER

#include "user.h"
#include "game.h"

class Automated_User : public User {

	private:

	public:
		Automated_User(): User(0, 0) {}
		Automated_User(int x, int y): User(x, y) {}

		void make_move(Game_State *) override;

};

#endif
