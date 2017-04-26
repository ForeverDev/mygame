#include <iostream>
#include <algorithm>
#include "town_hall.h"
#include "game.h"

Game_State::Game_State() {
	
	// initialize screen
	screen = vector<vector<Colored_Pixel>>(SCREEN_X);
	for (int i = 0; i < SCREEN_X; i++) {
		screen[i] = vector<Colored_Pixel>(SCREEN_Y);
		for (int j = 0; j < SCREEN_Y; j++) {
			Colored_Pixel pixel;
			pixel.c = UNKNOWN_DRAW_CHAR;
			pixel.color.foreground = FORE_WHITE;
			pixel.color.background = BACK_BLACK;
			screen[i][j] = move(pixel);
		}
	}

	// set default colors
	set_foreground(FORE_WHITE);
	set_background(BACK_BLACK);	

	auto town = make_shared<Town_Hall>();
	town->x = 5;
	town->y = 6;
	town->selection_index = 1;
	add_node(town);

	auto town2 = make_shared<Town_Hall>();
	town2->x = 8;
	town2->y = 13;
	town2->selection_index = 2;
	add_node(town2);

}

Game_State::~Game_State() {
	
	// reset colors on exit
	cout << "\x1b[0m" << endl;

}

void
Game_State::set_foreground(Foreground_Color color) {
	current_color.foreground = color;
	cout << "\x1b[" << static_cast<int>(color) << "m";
}

void
Game_State::set_background(Background_Color color) {
	current_color.background = color;
	cout << "\x1b[" << static_cast<int>(color) << "m";
}

void
Game_State::push_colors() {
	color_stack.push_back(current_color);	
}

void
Game_State::pop_colors() {
	if (color_stack.size() == 0) {
		return;
	}
	const auto& pop = color_stack.back();
	set_foreground(pop.foreground);
	set_background(pop.background);
	color_stack.pop_back();
}

void
Game_State::reset_screen() {
	for (int i = 0; i < SCREEN_X; i++) {
		for (int j = 0; j < SCREEN_Y; j++) {
			screen[i][j].c = ' ';
		}
	}
}

void
Game_State::render() {
	
	std::sort(nodes.begin(), nodes.end(), [](shared_ptr<Node> a, shared_ptr<Node> b) -> bool {
		return a->index < b->index;
	});

	for (auto& node: nodes) {
		node->render_to_array(screen);
	}

}

void
Game_State::draw() {

	for (int i = 0; i < SCREEN_Y; i++) {
		for (int j = 0; j < SCREEN_X; j++) {
			set_foreground(screen[j][i].color.foreground);
			set_background(screen[j][i].color.background);
			cout << screen[j][i].c << ' ';
		}
		cout << endl;
	}
	
}

void
Game_State::handle_input() {
	
	string input;
	cin >> input;
	
	auto nodes = get_nodes(5, 6);
	static_cast<Town_Hall *>(nodes[0])->selection_grabbed(this);

}

void
Game_State::add_node(const shared_ptr<Node>& node) {
	nodes.push_back(node);
}

vector<Node *>
Game_State::get_nodes(int x, int y) const {

	vector<Node *> found;

	for (auto& node: nodes) {
		if (node->x == x && node->y == y) {
			found.push_back(node.get());
		}
	}

	return found;

}
