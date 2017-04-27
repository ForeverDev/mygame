#ifndef GAME_H
#define GAME_H

#include <memory>
#include <vector>
#include "color.h"
#include "user.h"

using namespace std;

struct Text_Frame {
	int sx;
	int sy;
	int border;
	char border_char;
	vector<vector<Colored_Pixel>> pixels;

	Text_Frame(int, int);
	void put_string(int, int, const string&, const Color_Pair&);
	void put_char(int, int, char, const Color_Pair&);
	void fill(char);
	void draw();
};

class Game_State {

	public:
		const int SCREEN_X = 40;
		const int SCREEN_Y = 40;
		const int FRAME_X = SCREEN_X;
		const int FRAME_Y = 20;
		
		unique_ptr<Text_Frame> screen;
		unique_ptr<Text_Frame> frame;
			
		Game_State();
		~Game_State();
		void render();
		void draw();
		void handle_input();
		void reset_screen();

	private:
		
		static const char UNKNOWN_DRAW_CHAR = '.';
		vector<unique_ptr<User>> users;
		vector<Color_Pair> color_stack;
		Color_Pair current_color;

};

#endif
