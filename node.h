#ifndef NODE_H
#define NODE_H

#include <vector>
#include <string>
#include "color.h"

using namespace std;

class Node {

	public:
		static const int PX_SIZE = 5;
		
		int x = 0;
		int y = 0;
		int index = 0;
		
		virtual ~Node() {};
		virtual void render_to_array(vector<vector<Colored_Pixel>>&) = 0;

	private:

	protected:
		static void safe_char_put(vector<vector<Colored_Pixel>>&, int, int, const Color_Pair&, char);
		static void safe_string_put(vector<vector<Colored_Pixel>>&, int, int, const Color_Pair&, const string&);

};

#endif
