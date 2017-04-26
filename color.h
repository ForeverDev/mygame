#ifndef COLOR_H
#define COLOR_H

enum Foreground_Color {
	FORE_BLACK = 30,
	FORE_RED = 31,
	FORE_GREEN = 32,
	FORE_YELLOW = 33,
	FORE_BLUE = 34,
	FORE_MAGENTA = 35,
	FORE_CYAN = 36,
	FORE_WHITE = 37
};

enum Background_Color {
	BACK_BLACK = 40,
	BACK_RED = 41,
	BACK_GREEN = 42,
	BACK_YELLOW = 43,
	BACK_BLUE = 44,
	BACK_MAGENTA = 45,
	BACK_CYAN = 46,
	BACK_WHITE = 47
};

struct Color_Pair {
	Foreground_Color foreground;
	Background_Color background;

	Color_Pair(Foreground_Color fg, Background_Color bg): foreground(fg), background(bg) {}
	Color_Pair() {}
};

struct Colored_Pixel {
	char c;
	Color_Pair color;

	Colored_Pixel(char _c, Color_Pair _co): c(_c), color(_co) {}
	Colored_Pixel() {}
};

namespace const_color {
	static const auto WHITE		= Color_Pair(FORE_WHITE, BACK_BLACK);	
	static const auto RED		= Color_Pair(FORE_RED, BACK_BLACK);	
	static const auto GREEN		= Color_Pair(FORE_GREEN, BACK_BLACK);	
	static const auto YELLOW	= Color_Pair(FORE_YELLOW, BACK_BLACK);	
	static const auto BLUE		= Color_Pair(FORE_BLUE, BACK_BLACK);	
	static const auto MAGENTA	= Color_Pair(FORE_MAGENTA, BACK_BLACK);	
	static const auto CYAN		= Color_Pair(FORE_CYAN, BACK_BLACK);	
};

#endif
