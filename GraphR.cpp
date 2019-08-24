//============================================================================
// Name        : Graphs_Raul_UFRJ_2019.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "Graphmr.h"

int main()	 {
	/*
	Graphmr g;
	g.runGraph("dblp.txt", 'v', 'b', 1, true, true);
	//g.CC();
	*/

	//*****************************************************************************************************
	//Estudo de Caso **** (Item 2 e Item 3): Executar 1000 BFS e DFS to get the average search time
	double time_bfs = 0;
	double time_dfs = 0;
	double time_taken;
	int n_rand;
	int iterations = 1000;
	clock_t start, end;

	Graphmr g;
    g.openFile("dblp.txt");	// read // as_graph // dblp // live_journal
    g.buildGraph('v');			// 'm' = matriz, 'l' = lista , 'v' = vetor
    // Running BFS and DFS one thousand times.
    cout << "Run BFS and DFS " << iterations << " times." <<endl;
    for(int i = 0; i<iterations; i++){
    	//Choses a random vertex
    	g.loadPercent(i, iterations);
    	n_rand = rand() % g.getN_vertices() + 1;  // n_rand in the range 1 to n_vertices
    	//Measures the time (BFS)
        start = clock();
        g.BFS(n_rand);
        end = clock();
        time_taken = double(end - start) / double(CLOCKS_PER_SEC);
        time_bfs = time_bfs + time_taken;
        //Measures the time (DFS)
        start = clock();
        g.DFS(n_rand);
        end = clock();
        time_taken = double(end - start) / double(CLOCKS_PER_SEC);
        time_dfs = time_dfs + time_taken;
    }
    time_bfs = time_bfs/iterations;
    time_dfs = time_dfs/iterations;
    cout << "Time taken by program is on average (BFS): " << time_bfs <<endl;
    cout << "Time taken by program is on average (DFS): " << time_dfs <<endl;
	//************************************************************************************************

    return 0;
}
