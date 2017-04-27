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

	private:

	protected:

};

#endif
