/*
 * Graphmr.h
 *  Created on: 1 de fev de 2019
 *      Author: Raul
 *      Collaborator: Luís
 */

#ifndef GRAPHMR_H_
#define GRAPHMR_H_

#include <iostream>
#include <fstream>
#include <algorithm>   	 	//std::sort
#include <queue>
#include <stack>
#include <string>
#include <vector>			//std::vector
#include <ctime>		 	//time_t
#include <climits>			//INT_MAX
#include <cfloat>			//FLT_MAX
#include <functional>		//greater used in MEAN-HEAP (Dijkstra algorithm)

using namespace std;
using std::vector;

typedef pair<double, int> par_distV;
typedef pair<double, int> par_cost;


class listElement{
	friend class Graphmr;	//grants access to Graphmr member variables

	private:
		listElement* link; 	//pointer to implement pseudo linked list
		int vertex; 		// vertex id
		double w;			// weight
};

class Graphmr {

private:

	char structure; 			//'m' = Matrix, 'l' = List, 'v' = Vector

	int maxFlow;
	int n_edges;				//Number of edges.
	int n_vertices;				//Number of vertices.
	int d_min;					//degree min
	int d_max;					//degree max
	int components;				//number of components
	int diameter;				//graph diameter
	int level_Max;				//used to find the diameter
	int* size; 					//component size
	int* Degree; 				//stores each vertex degree (non-directed graph)
	int* Parent;				//stores each vertex - parent
	int* Parent_b;				//stores each vertex - parent (used by bfs in FordFulkerson)
	int* Level;					//stores each vertex - level
	int* visited;
	int* bipartidoGroup;
	int** rGraph;				//Residual Graph

	vector<int> ordDegree;		//stores each vertex degree - median (non-directed graph)
	vector<int> inDegree;		//stores entry degree (directed graph)
	vector<int> outDegree;		//stores output degree (directed graph)
	vector<vector<int> > vec;	//adjacency vector
	vector<vector<float> > vec_W;//adjacency vector (Store weights)

	float d_mean;				//degree mean
	float d_median;				//degree median
	float** adMatrix_dir;		//Adjacency matrix (directed graph)

	double eccentricity;
	double* Bellman_dist;

	bool ciclo_bellman;
	bool bipartite;
	bool print;					//output (ofstream)
	bool oriented;				//True = directed graph; False = non-directed graph
	bool weight;				//True = weighted graphs; False = unweighted graphs (all edges have unit weight)
	bool error_1 = false;		//checks if the file was open correctly
	bool error_2 = false;		//checks if the structure is valid
	bool* Explored; 			//explored vertices
	bool* Explored_b; 			//explored vertices (used by bfs in FordFulkerson)
	bool** adMatrix;			//adjacency matrix

	listElement** adList;		//adjacency list
	listElement** adList_rGraph;//adjacency list (Residual Graph)
	string path;
	ifstream file;
	time_t begin,end;			//time_t is a datatype to store time values.
	par_distV* dist_v;
	par_cost* cost;

public:

	Graphmr();					//char const* path);//Construtor default
	~Graphmr();					//Destrutor da classe
	//GETTERS - accessor methods
	bool get_ciclo_bellman();
	bool get_bipartite();
	int getN_edges();
	int getN_vertices();
	int getD_min();
	int getD_max();
	int get_Parent(int v);
	int get_Level(int v);
	int get_level_Max();
	int get_minsizecc();
	int get_maxsizecc();
	int get_Diameter();
	int get_maxFlow();
	float getD_mean();
	float getD_median();
	double get_dist_v(int v);
	double get_cost(int v);
	double get_eccentricity();
	double get_MST_cost();
	double get_Bellman_dist(int v);

	//SETTERS - mutator methods
	void setN_edges();
	void setN_vertices();
	void setD_min(int value);
	void setD_max(int value);
	void setD_mean(float value);
	void setD_median();
	void set_maxFlow(int flow);

	void set_bipartite(bool b);
	void set_print(bool generate);
	void set_DELP();
	void set_Degree();
	void set_Explored();
	void set_Level();
	void set_Parent();
	void set_Diameter();
	void set_dist_v();
	void set_cost();
	void set_weight(bool w);
	void set_oriented(bool o);
	void set_eccentricity(char algorithm);
	void set_Parent_b();
	void set_Explored_b();
	void set_Bellman_dist();

	// Functions
	void openFile(string path);
	void buildGraph(char structure);
	void InfoDegree();

	void BFS(int s);
	void DFS(int s);
	void CC();
	void Dijkstra(int s);
	void Prim(int s);
	void BellmanFord(int t);
	void FordFulkerson(int s, int t);
	bool bfs(int s, int t);

	void runGraph(string path, char structure, char search, int v_init, bool info, bool print);
	void loadPercent(int p, int n);
};

#endif /* GRAPHMR_H_ */
