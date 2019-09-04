//============================================================================
// Name        : Graphs_Raul_UFRJ_2019.cpp
// Author      : Raul
// Collaborator: Luís
// Version     : 1.0
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "Graphmr.h"

int main()	 {
	///*// runGraph(string path, char structure, char search, int v_init, bool info, bool print);
	Graphmr g;
	g.runGraph("dblp.txt", 'l', 'b', 1, true, true);
	//g.CC();
	//*/
	/*
    //================================================================================================
	//Estudo de Caso **** (Item 2 e Item 3): Executar 1000 BFS e DFS to get the average search time
	double time_bfs = 0;
	double time_dfs = 0;
	double time_taken;
	int n_rand;
	int iterations = 1000;
	clock_t start, end;

	Graphmr g;
    g.openFile("live_journal.txt");	// read // as_graph // dblp // live_journal
    g.buildGraph('v');			// 'm' = matriz, 'l' = lista , 'v' = vetor
    // Running BFS and DFS one thousand times.
    cout << "Run BFS and DFS " << iterations << " times." <<endl;
    for(int i = 0; i<iterations; i++){
    	//Choses a random vertex
    	g.loadPercent(i, iterations-1);
    	n_rand = rand() % g.getN_vertices() + 1;  // n_rand in the range 1 to n_vertices
    	//Measures the time (BFS)
        g.set_DELP();
        start = clock();
        g.BFS(i+1);//n_rand
        end = clock();
        time_taken = double(end - start) / double(CLOCKS_PER_SEC);
        time_bfs = time_bfs + time_taken;
        //Measures the time (DFS)
        g.set_DELP();
        start = clock();
        g.DFS(i+1);
        end = clock();
        time_taken = double(end - start) / double(CLOCKS_PER_SEC);
        time_dfs = time_dfs + time_taken;
    }
    time_bfs = time_bfs/iterations;
    time_dfs = time_dfs/iterations;
    cout << "Time taken by program is on average (BFS): " << time_bfs <<endl;
    cout << "Time taken by program is on average (DFS): " << time_dfs <<endl;
    //================================================================================================
    //*/
	/*
    //================================================================================================
    //Estudo de Caso **** (Item 4) Determine o pai dos vértices 10, 20, 30 na árvore geradora induzida
    //pela BFS e pela DFS quando iniciamos a busca nos vértices 1, 2, 3
    int initial_vertex = 1;
	Graphmr g;
    g.openFile("dblp.txt");	// read // as_graph // dblp // live_journal
    g.buildGraph('v');		// 'm' = matriz, 'l' = lista , 'v' = vetor
    g.BFS(initial_vertex);
    cout << "BFS - Busca iniciada no vértice: " << initial_vertex <<endl;
    cout << "Pai do vértice 10: " << g.get_Parent(10) 	<<endl;
    cout << "Pai do vértice 20: " << g.get_Parent(20) 	<<endl;
    cout << "Pai do vértice 30: " << g.get_Parent(30) 	<<endl;
    g.set_DELP();
    g.DFS(initial_vertex);
    cout << "DFS - Busca iniciada no vértice: " << initial_vertex <<endl;
    cout << "Pai do vértice 10: " << g.get_Parent(10) 	<<endl;
    cout << "Pai do vértice 20: " << g.get_Parent(20) 	<<endl;
    cout << "Pai do vértice 30: " << g.get_Parent(30) 	<<endl;
    //================================================================================================
    //*/
	/*
    //================================================================================================
	//Estudo de Caso **** (Item 5)
	//Determine a distância entre os seguintes pares de vértices (10,20), (10,30), (20,30).
	Graphmr g;
    g.openFile("dblp.txt");	// read // as_graph // dblp // live_journal
    g.buildGraph('v');		// 'm' = matriz, 'l' = lista , 'v' = vetor
    int x = 10;
    int y = 20;
    g.BFS(x);
    cout << "Distância entre o par (" << x << "," << y << "): " << g.get_Level(y) <<endl;
    y = 30;
    cout << "Distância entre o par (" << x << "," << y << "): " << g.get_Level(y) <<endl;
    x = 20;
    g.set_Level();
    g.set_Parent();
    g.set_Explored();
    g.BFS(x);
    cout << "Distância entre o par (" << x << "," << y << "): " << g.get_Level(y) <<endl;
    //================================================================================================
    //*/
    /*
    //================================================================================================
	//Estudo de Caso **** (Item 6) Obtenha as componentes conexas do grafo.
	//Quantas componentes conexas tem o grafo? Qual é o tamanho da maior e da menor componente conexo?
	Graphmr g;
    g.openFile("dblp.txt");	// read // as_graph // dblp // live_journal
    g.buildGraph('v');		// 'm' = matriz, 'l' = lista , 'v' = vetor
    g.CC();
    cout << "Menor componente conexa: " << g.get_minsizecc() <<endl;
    cout << "Maior componente conexa: " << g.get_maxsizecc() <<endl;
    return 0;
    //================================================================================================
	//*/
    /*
    //================================================================================================
    //Estudo de Caso **** (Item 7) Determine o diâmetro do grafo. Determine também o tempo que sua
    //biblioteca levou para fazer este cálculo.
	Graphmr g;
    g.openFile("as_graph.txt");	// read // as_graph // dblp // live_journal
    g.buildGraph('l');		// 'm' = matriz, 'l' = lista , 'v' = vetor
	clock_t start, end;
	double time_taken;
    start = clock();
    g.set_Diameter();
    end = clock();
    time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    cout << "O diâmetro do grafo é: " << g.get_Diameter() <<endl;
    cout << "Time taken by program : " << time_taken <<endl;
    //================================================================================================
	//*/
}
