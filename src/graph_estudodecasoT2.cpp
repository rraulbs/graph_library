/*
 * graph_estudodecasoT2.cpp
 *
 *  Created on: 20 de nov de 2019
 *      Author: Raul
 */
//#include "Graphmr.h"
//int main(){return 0;}


/*/
	Graphmr g;
	g.openFile("T2_exemplo3.txt");
	g.set_weight(true);
	g.buildGraph('l');
	g.set_print(true);
	g.Prim(1);
	/*/
	/*
    //========================ESTUDO DE CASO TRABALHO 2: =============================================
	//================================================================================================
	//Estudo de Caso **** (Item 1): Calcule a distância e o caminho mínimo entre o vértice 1 e
	//os vértices 10, 20, 30, 40, 50.
	Graphmr g;
	g.openFile("grafo_1.txt");
	g.set_weight(true);
	g.buildGraph('l');
	g.Dijkstra(1);
	cout <<"Distância (1,10) = " << g.get_dist_v(10) <<endl;
	cout <<"Distância (1,20) = " << g.get_dist_v(20) <<endl;
	cout <<"Distância (1,30) = " << g.get_dist_v(30) <<endl;
	cout <<"Distância (1,40) = " << g.get_dist_v(40) <<endl;
	cout <<"Distância (1,50) = " << g.get_dist_v(50) <<endl;
	int v = 10;
	cout <<"Caminho mínimo entre vértice 1 e "<< v <<": "<<endl;
	int u;
	while (g.get_Parent(v)!= 0){
		u = g.get_Parent(v);
		//cout<< "pai de " << v << " = " << u <<endl;
		cout<< v << ",";
		v = u;
	}
	cout << v <<endl;
	//================================================================================================
	//*/
	/*
	//================================================================================================
	//Estudo de Caso **** (Item 2): Calcule a excentricidade dos vértices 10, 20, 30, 40, 50.
	Graphmr g;
	g.openFile("grafo_2.txt");
	g.set_weight(true);
	g.buildGraph('l');						//MUDAR ESTRUTURA AQUI: m = matriz, l = lista, v = vetor
	int vertex = 10;						//MUDAR VÉRTICE AQUI: 10,20,30,40,50
	g.Dijkstra(vertex);
	g.set_eccentricity('d');				//Excentricidade: d = Dijkstra
	cout <<"eccentricity vertex " << vertex <<" = " << g.get_eccentricity() <<endl;
	cout <<"eccentricity vertex (int) " << vertex <<" = " << int(g.get_eccentricity()) <<endl;
	//================================================================================================
	//*/
	/*/
	//================================================================================================
	//Estudo de Caso **** (Item 3): Determine o tempo médio para calcular a excentricidade.
	//Ou seja, escolha n vértices iniciais (ex. n = 100) de forma aleatória e calcule a excentricidade
	//deles marcando o tempo e fazendo a média amostral.
	clock_t start, end;
	double time_taken = 0.0;
	double time_r = 0.0;
	int n_rand;
	//int iterations = 1000;
	Graphmr g;
	g.openFile("grafo_5.txt");
	g.set_weight(true);
	g.buildGraph('l');						//MUDAR ESTRUTURA AQUI: m = matriz, l = lista, v = vetor
	int n = 100;
	for(int i = 0; i < n; i++){
    	g.loadPercent(i, n-1);
    	n_rand = rand() % g.getN_vertices() + 1;  // n_rand in the range 1 to n_vertices
        g.set_DELP();
        g.set_dist_v();
        start = clock();
		g.Dijkstra(n_rand); //n_rand
		g.set_eccentricity('d');			//Excentricidade: d = Dijkstra
        end = clock();
        time_taken = double(end - start) / double(CLOCKS_PER_SEC);
        time_r = time_r + time_taken;
	}
	time_r = time_r/n;
    cout << "Time taken: " << time_r <<endl;
	//================================================================================================
	//*/
	/*/
	//================================================================================================
	//Estudo de Caso **** (Item 4): Obtenha uma árvore geradora mínima, informando seu peso. Obtenha
	//o tempo de execução para reseolver este problema.
	clock_t start, end;
	double time_taken = 0.0;
	double time_r = 0.0;
	int n_rand;
	Graphmr g;
	g.openFile("grafo_1.txt");
	g.set_weight(true);
	g.buildGraph('l');						//MUDAR ESTRUTURA AQUI: m = matriz, l = lista, v = vetor
	int n = 100;
	for(int i = 0; i < n; i++){
    	g.loadPercent(i, n-1);
    	n_rand = rand() % g.getN_vertices() + 1;  // n_rand in the range 1 to n_vertices
        g.set_DELP();
        g.set_cost();
    	//g.print(true);						//Para gerar: Prim-Tree.txt contendo MST e o custo.
        start = clock();
    	g.Prim(n_rand);
        end = clock();
        time_taken = double(end - start) / double(CLOCKS_PER_SEC);
        time_r = time_r + time_taken;
	}
	time_r = time_r/n;
	double MST = g.get_MST_cost();
	cout << "Peso da MST (double) = " << MST <<endl;
	cout << "Peso da MST (int) = " << int(MST) <<endl;
	cout << "Time taken T(MST): " << time_r <<endl;
	//================================================================================================
	//*/

	/*
	int dijkstra = 2722;
	int turing = 11365;
	int kruskal = 471365;
	int kleinberg = 5709;
	int tardos = 11386;
	int figueiredo = 343930;
	Graphmr g;
	g.openFile("rede_colaboracao.txt");
	g.set_weight(true);
	g.buildGraph('l');
	g.Dijkstra(dijkstra);
	cout <<"Distância (1,10) = " << double(g.get_dist_v(turing)) <<endl;
	cout <<"Distância (1,20) = " << double(g.get_dist_v(kruskal)) <<endl;
	cout <<"Distância (1,30) = " << double(g.get_dist_v(kleinberg)) <<endl;
	cout <<"Distância (1,40) = " << double(g.get_dist_v(tardos)) <<endl;
	cout <<"Distância (1,50) = " << double(g.get_dist_v(figueiredo)) <<endl;
	int v = 343930;
	cout <<"Caminho mínimo entre vértice 1 e "<< v <<": "<<endl;
	int u;
	while (g.get_Parent(v)!= 0){
		u = g.get_Parent(v);
		//cout<< "pai de " << v << " = " << u <<endl;
		cout<< v << ",";
		v = u;
	}
	cout << v <<endl;


	*/

