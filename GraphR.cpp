//============================================================================
// Name        : Graphs_Raul_UFRJ_2019.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "Graphmr.h"

int main()	 {
	Graphmr g;
	g.runGraph("as_graph.txt", 'v', 'b', 1, true, true);
	g.CC();
    return 0;
}
