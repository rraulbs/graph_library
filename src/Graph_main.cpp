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
	// Estudo de caso Trabalho 3
	/*// Emparelhamento Máximo - Utilizando Ford-Fulkerson
	int s,t;
	Graphmr g;
	g.openFile("grafo_teste_1.txt");
	g.buildGraph('l');
	g.set_print(true);
	g.BFS(1);
	if(g.get_bipartite()){ // Se o grafo é bipartido, constroi rede de fluxo
		s = g.getN_vertices() + 1;
		t = g.getN_vertices() + 2;
		g.FordFulkerson(s, t);
		cout << "Max flow = " << g.get_maxFlow()<<endl;
	}
	//*/
	//*// Bellman-Ford
	int t;
	t = 6;
	Graphmr g;
	g.openFile("bellman_example.txt");
	g.set_oriented(true);
	g.set_weight(true);
	g.buildGraph('l');
	g.BellmanFord(t);
	if(g.get_ciclo_bellman()==false){
		for(int i = 0; i < g.getN_vertices(); i++){
			cout<< "M[" <<i+1 <<"] =" << g.get_Bellman_dist(i+1)<<endl;
		}
	}
	//*/
}

