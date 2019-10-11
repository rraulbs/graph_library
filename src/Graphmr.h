/*
 * Graphmr.h
 *  Created on: 1 de fev de 2019
 *      Author: Raul
 *      Collaborator: Lu�s
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

using namespace std;
using std::vector;

class listElement{
	friend class Graphmr;	//grants access to Graphmr member variables

	private:
		listElement* link; 	//pointer to implement pseudo linked list
		int vertex; 		// vertex id
		float w;			// weight
};

class Graphmr {

private:

	char structure; 			//'m' = Matrix, 'l' = List, 'v' = Vector

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
	int* Level;					//stores each vertex - level
	vector<int> ordDegree;		//stores each vertex degree - median (non-directed graph)
	vector<int> inDegree;		//stores entry degree (directed graph)
	vector<int> outDegree;		//stores output degree (directed graph)
	vector<vector<int> > vec;	//adjacency vector

	float d_mean;				//degree mean
	float d_median;				//degree median

	bool print;					//output (ofstream)
	bool oriented;				//True = directed graph; False = non-directed graph
	bool weight;				//True = weighted graphs; False = unweighted graphs (all edges have unit weight)
	bool error_1 = false;		//checks if the file was open correctly
	bool error_2 = false;		//checks if the structure is valid
	bool* Explored; 			//explored vertices
	bool** adMatrix;			//adjacency matrix

	listElement** adList;		//adjacency list
	string path;
	ifstream file;
	time_t begin,end;			//time_t is a datatype to store time values.

public:
	float** adMatrix_dir;		//Adjacency matrix (directed graph)

	Graphmr();					//char const* path);//Construtor default
	~Graphmr();					//Destrutor da classe

	//GETTERS - accessor methods
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
	float getD_mean();
	float getD_median();

	//SETTERS - mutator methods
	void setN_edges();
	void setN_vertices();
	void setD_min(int value);
	void setD_max(int value);
	void setD_mean(float value);
	void setD_median();

	void set_DELP();
	void set_Degree();
	void set_Explored();
	void set_Level();
	void set_Parent();
	void set_Diameter();

	void openFile(string path);
	void buildGraph(char structure, bool oriented, bool weight);
	void InfoDegree();

	void BFS(int s);
	void DFS(int s);
	void CC();

	void runGraph(string path, char structure, char search, int v_init, bool info, bool print);
	void loadPercent(int p, int n);
};

#endif /* GRAPHMR_H_ */