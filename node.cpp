#include "node.h"
#include "color.h"

void
Node::safe_char_put(vector<vector<Colored_Pixel>>& grid, int x, int y, const Color_Pair& color, char c) {
	if (x >= grid.size() || x < 0) {
		return;
	}
	if (y >= grid[0].size() || y < 0) {
		return;
	}
	grid[x][y].color = color;
	grid[x][y].c = c;
}

void
Node::safe_string_put(vector<vector<Colored_Pixel>>& grid, int x, int y, const Color_Pair& color, const string& str) {
	for (int i = 0; i < str.length(); i++) {
		safe_char_put(grid, x + i, y, color, str[i]);
	}
}
