#ifndef GAME_H
#define GAME_H

#include <memory>
#include <vector>
#include "node.h"
#include "color.h"

using namespace std;

class Game_State {

	public:
		static const int SCREEN_X = 40;
		static const int SCREEN_Y = 40;
		
		vector<vector<Colored_Pixel>> screen;		
		
		Game_State();
		~Game_State();
		void render();
		void draw();
		void handle_input();
		void reset_screen();
		void add_node(const shared_ptr<Node>&);
		vector<Node *> get_nodes(int, int) const;

	private:
		
		static const char UNKNOWN_DRAW_CHAR = '.';
		vector<shared_ptr<Node>> nodes;
		vector<Color_Pair> color_stack;
		Color_Pair current_color;

		void set_foreground(Foreground_Color);
		void set_background(Background_Color);
		void push_colors();
		void pop_colors();

};

#endif
