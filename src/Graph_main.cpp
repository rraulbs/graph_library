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
	/*
	Graphmr g;
	g.openFile("T2_exemplo.txt");
	g.buildGraph('m', true, true);
	for (int i = 0; i < g.getN_vertices(); i++){
		for(int j = 0; j < g.getN_vertices(); j++){
			cout<< g.adMatrix_dir[i][j] << "\t";
		}
		cout<<endl;
	}
	//*/
	Graphmr g;
	g.openFile("T2_exemplo.txt");
	g.buildGraph('v', true, true);
	cout<< g.vec[0][0] << " # " << g.vec_W[0][0] <<endl;
	cout<<g.vec[0].size();


	/*
	//vector<vector<vector<int> > > vec (5,vector<vector<int> >(3,vector <int>(2,4)));
	//cout << vec[0][0][0] << endl;
	//cout << vec[0][0][1] << endl;
	vector<vector<vector<int> > > v (3,vector<vector<int> >(3,vector <int>()));
	v[0][0].push_back(4);
	v[0][0].push_back(2);
	cout << v[0][0][0]<<endl;
	cout << v[0][0][1]<<endl;
	*/
}
