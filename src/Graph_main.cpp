//============================================================================
// Name        : Graphs_Raul_UFRJ_2019.cpp
// Author      : Raul
// Collaborator: Luís
// Version     : 1.0
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "Graphmr.h"

//typedef pair<int, float> pi;

int main(){
	/*
    //========================ESTUDO DE CASO TRABALHO 2: =============================================
	//================================================================================================
	//Estudo de Caso **** (Item 1): Calcule a distância e o caminho mínimo entre o vértice 1 e
	//os vértices 10, 20, 30, 40, 50.
	Graphmr g;
	g.openFile("grafo_1.txt");
	g.set_weight(true);
	g.buildGraph('m');
	g.Dijkstra(1);
	cout <<"Distância (1,10) = " << g.get_dist_v(10) <<endl;
	cout <<"Distância (1,20) = " << g.get_dist_v(20) <<endl;
	cout <<"Distância (1,30) = " << g.get_dist_v(30) <<endl;
	cout <<"Distância (1,40) = " << g.get_dist_v(40) <<endl;
	cout <<"Distância (1,50) = " << g.get_dist_v(50) <<endl;
	int v = 30;
	cout <<"Caminho mínimo entre vértice 1 e "<< v <<": "<<endl;
	int u;
	while (g.get_Parent(v)!= 0){
		u = g.get_Parent(v);
		//cout<< "pai de " << v << " = " << u <<endl;
		cout<< v <<endl;
		v = u;
	}
	cout << v <<endl;
	//================================================================================================
	//*/
	/*
	//================================================================================================
	//Estudo de Caso **** (Item 2): Calcule a excentricidade dos vértices 10, 20, 30, 40, 50.
	Graphmr g;
	g.openFile("grafo_1.txt");
	g.set_weight(true);
	g.buildGraph('m');						//MUDAR ESTRUTURA AQUI: m = matriz, l = lista, v = vetor
	int vertex = 50;						//MUDAR VÉRTICE AQUI: 10,20,30,40,50
	g.Dijkstra(vertex);
	g.set_eccentricity();
	cout <<"eccentricity vertex " << vertex <<" = " << g.get_eccentricity() <<endl;
	//================================================================================================
	//*/
	///*/
	//================================================================================================
	//Estudo de Caso **** (Item 3): Determine o tempo médio para calcular a excentricidade.
	//Ou seja, escolha n vértices iniciais (ex. n = 100) de forma aleatória e calcule a excentricidade
	//deles marcando o tempo e fazendo a média amostral.
	clock_t start, end;
	double time_taken = 0.0;
	double time_r = 0.0;
	Graphmr g;
	g.openFile("grafo_1.txt");
	g.set_weight(true);
	g.buildGraph('m');						//MUDAR ESTRUTURA AQUI: m = matriz, l = lista, v = vetor
	int n = 100;
	for(int i = 0; i < n; i++){
        start = clock();
		g.Dijkstra(i+1);
		g.set_eccentricity();
        end = clock();
        time_taken = double(end - start) / double(CLOCKS_PER_SEC);
        time_r = time_r + time_taken;
	}
	time_r = time_r/n;
    cout << "Time taken: " << time_r <<endl;
	//================================================================================================
	//*/

	/*
	Graphmr g;
	g.openFile("grafo_1.txt");
	g.buildGraph('m', false, true);
	for (int i = 0; i < g.getN_vertices(); i++){
		for(int j = 0; j < g.getN_vertices(); j++){
			cout<< g.adMatrix_dir[i][j] << "\t";
		}
		cout<<endl;
	}
	g.Dijkstra(1);
	cout << "DISTANCIAS" <<endl;
	for (int i = 0; i < g.getN_vertices(); i++){
		cout << g.get_dist_v(i+1) <<endl;
	}
	*/
}

