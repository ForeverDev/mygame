#include <iostream>
#include "game.h"

// text frame implementation.....
Text_Frame::Text_Frame(int _sx, int _sy) {
	sx = _sx;
	sy = _sy;

	pixels = vector<vector<Colored_Pixel>>(_sx);
	for (int i = 0; i < _sx; i++) {
		pixels[i] = vector<Colored_Pixel>(_sy);
		for (int j = 0; j < _sy; j++) {
			pixels[i][j].c = ' ';
			pixels[i][j].color = const_color::WHITE;
		}
	}
}

void
Text_Frame::put_string(int x, int y, const string& str, const Color_Pair& color) {
	for (int i = 0; i < str.length(); i++) {
		if (x >= sx) {
			x = 0;
			y++;
		}
		if (y >= sy) {
			return;
		}
		pixels[x][y].c = str[i];
		pixels[x][y].color = color;
		x++;
	}
}

void
Text_Frame::put_char(int x, int y, char c, const Color_Pair& color) {
	if (x < 0 || x >= sx || y < 0 || y >= sy) {
		return;
	}
	pixels[x][y].c = c;
	pixels[x][y].color = color;	
}

void
Text_Frame::fill(char c) {
	for (auto& pixel_row: pixels) {
		for (auto& pixel: pixel_row) {
			pixel.c = c;
		}
	}
}

void
Text_Frame::draw() {
	
	for (int i = 0; i < sy; i++) {
		for (int j = 0; j < sx; j++) {
// colors only supported for OSX
#ifdef __APPLE__
			cout << "\x1b[" << pixels[j][i].color.foreground << "m";
			cout << "\x1b[" << pixels[j][i].color.background << "m";
#endif
			cout << pixels[j][i].c << ' '; 
		}
		cout << endl;
	}

}

// game state implementation.....
Game_State::Game_State() {

	screen = make_unique<Text_Frame>(SCREEN_X, SCREEN_Y);
	frame  = make_unique<Text_Frame>(FRAME_X, FRAME_Y);

	screen->fill('.');
	screen->put_string(0, 0, "hello", const_color::WHITE);
	frame->fill('~');


}

Game_State::~Game_State() {
	
	// reset colors on exit
	cout << "\x1b[0m" << endl;

}

void
Game_State::reset_screen() {
}

void
Game_State::render() {

	for (auto& user: users) {
		user->make_move(this);
	}

}

void
Game_State::draw() {

	screen->draw();
	frame->draw();
	
}

void
Game_State::handle_input() {
	
	string input;
	cin >> input;
	
}
