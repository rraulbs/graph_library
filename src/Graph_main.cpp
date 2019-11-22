//============================================================================
// Name        : Graphs_Raul_UFRJ_2019.cpp
// Author      : Raul
// Collaborator: Luís
// Version     : 1.0
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "Graphmr.h"


int main(){
	int s,t;
	Graphmr g;
	g.openFile("grafo_teste_3.txt");
	g.buildGraph('m');
	g.set_print(true);
	g.BFS(1);
	if(g.get_bipartite()){ // Se o grafo é bipartido, constroi rede de fluxo
		s = g.getN_vertices() + 1;
		t = g.getN_vertices() + 2;
		g.FordFulkerson(s, t);
		cout << "Max flow = " << g.get_maxFlow()<<endl;
	}
}

