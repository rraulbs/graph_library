/*
 * Graphmr.cpp
 *
 *  Created on: 1 de fev de 2019
 *      Author: Raul
 */
#include "Graphmr.h"

Graphmr::Graphmr() {//(char const* path) : file(path)
	// TODO Auto-generated constructor stub
	this-> d_min = INT_MAX;
	this-> d_max = INT_MIN;
	this-> diameter = -1;
	this-> level_Max = INT_MIN;
	this-> d_mean = 0;
	this-> print = false;
	this-> weight = false;
	this-> oriented = false;
	this-> bipartite = true;
	this-> ciclo_bellman = false;
}

Graphmr::~Graphmr() {
	// TODO Auto-generated destructor stub
}

//GETTERS - accessor methods
bool Graphmr::get_bipartite(){
	return bipartite;
}
bool Graphmr::get_ciclo_bellman(){
	return ciclo_bellman;
}
int Graphmr::getN_edges(){
	return n_edges;
}
int Graphmr::getN_vertices(){
	return n_vertices;
}
int Graphmr::getD_min(){
	return d_min;
}
int Graphmr::getD_max(){
	return d_max;
}
float Graphmr::getD_mean(){
	return d_mean;
}
float Graphmr::getD_median(){
	return d_median;
}

int Graphmr::get_Parent(int v){
	return Parent[v-1];
}
int Graphmr::get_Level(int v){
	return Level[v-1];
}
int Graphmr::get_minsizecc(){
	int min_size = INT_MAX;
	for(int i = 0; i <components ; i++){
		min_size = min(size[i], min_size);
	}
	return min_size;
}
int Graphmr::get_maxsizecc(){
	int max_size = INT_MIN;
	for(int i = 0; i< components; i++){
		max_size = max(size[i], max_size);
	}
	return max_size;
}
int Graphmr::get_level_Max(){
	return level_Max;
}
int Graphmr::get_Diameter(){
	return diameter;
}
int Graphmr::get_maxFlow(){
	return maxFlow;
}
double Graphmr::get_dist_v(int v){
	return dist_v[v-1].first;
}
double Graphmr::get_cost(int v){
	return cost[v-1].first;
}
double Graphmr::get_MST_cost(){
	double total = 0.0;
	for(int i = 0; i<n_vertices; i++){
		total = total + cost[i].first;
	}
	return total;
}
double Graphmr::get_eccentricity(){
	return eccentricity;
}


//SETTERS - mutator methods
void Graphmr::setD_min(int value){
	d_min = min(d_min, value);
}
void Graphmr::setD_max(int value){
	d_max = max(d_max, value);
}
void Graphmr::setD_mean(float value){
	d_mean = value;
}
void Graphmr::setD_median(){
	//calculando median dos graus: d_median.
	sort(ordDegree.begin(), ordDegree.end());
	int mdn = (n_vertices + 1)/2;
	if ( (n_vertices % 2) == 0 ){
		d_median = (ordDegree[mdn-1] + ordDegree[mdn])/2.0;
	}
	else{
		d_median = ordDegree[mdn-1];
	}
}
void Graphmr::set_print(bool generate){
	print = generate;
}
void Graphmr::set_bipartite(bool b){
	bipartite = b;
}
void Graphmr::set_DELP(){
	for (int i=0; i<n_vertices; i++){
		Degree[i] = 0;
		Explored[i] = false;
		Level[i] = 0;
		Parent[i] = -1;
	}
}
void Graphmr::set_Degree(){
	for (int i=0; i<n_vertices; i++){
		Degree[i] = 0;
	}
}
void Graphmr::set_Explored(){
	for (int i = 0; i < n_vertices; i++){
		Explored[i] = false;
	}
}
void Graphmr::set_Level(){
	for (int i=0; i<n_vertices ;i++){
		Level[i] = 0;
	}
}
void Graphmr::set_Parent(){
	for(int i=0; i<n_vertices; i++){
		Parent[i] = -1;
	}
}
void Graphmr::set_Cor(){
	for(int i = 0; i < n_vertices; i++){
		Cor[i] = -1;
	}
}
void Graphmr::set_dist_v(){
	for(int i = 0; i<n_vertices; i++){
		dist_v[i].first = DBL_MAX;
		dist_v[i].second = i+1;
	}
}
void Graphmr::set_cost(){
	for(int i = 0; i<n_vertices; i++){
		cost[i].first = DBL_MAX;
		cost[i].second = i+1;
	}
}
void Graphmr::set_Diameter(){
	clock_t start, end;
	double time_taken;
	double total = 0;
    for (int i = 1; i < getN_vertices() + 1; i++){
    	loadPercent(i, getN_vertices());
    	set_DELP();
        start = clock();
    	BFS(i);
    	diameter = max(diameter, get_level_Max());
        end = clock();
        total = double(end - start) / double(CLOCKS_PER_SEC);
        time_taken = time_taken + total;
    }
    cout << "Time taken by program inside: " << time_taken <<endl;
}
void Graphmr::set_weight(bool w){
	weight = w;
}
void Graphmr::set_oriented(bool o){
	oriented = o;
}
void Graphmr::set_eccentricity(char algorithm){ //algorithm: d = Dijkstra, p = "prim";
	eccentricity = DBL_MIN;
	switch (algorithm){
	case 'd':
		for(int i = 0; i < n_vertices; i++){
			eccentricity = max(eccentricity, dist_v[i].first);
		}
		break;
	case 'p':
		for(int i = 0; i < n_vertices; i++){
			eccentricity = max(eccentricity, cost[i].first);
		}
		break;
	default:
		cout<<"Undefined value, select: Dijkstra = 'd', Prim = 'p'"<<endl;
	}
}
void Graphmr::set_maxFlow(int flow){
	maxFlow = flow;
}
void Graphmr::set_Parent_b(){
	for(int i=0; i<n_vertices+2; i++){
		Parent_b[i] = -1;
	}
}
void Graphmr::set_Explored_b(){
	for (int i = 0; i < n_vertices+2; i++){
		Explored_b[i] = false;
	}
}
void Graphmr::set_Bellman_dist(){
	for (int i = 0; i < n_vertices; i++){
		Bellman_dist[i] = DBL_MAX;
	}
}
//Functions*******************************************
void Graphmr::openFile(string path){
	file.open(path.c_str()); // ("exemplo.txt, std::ifstream::in);
	if (file.is_open()){
		error_1 = false;
		cout << "File is open successfully!"<<endl;
	}
	else{
		error_1 = true;
		cout<< "File is not open! It was not possible to read the file,"
				" check if you put the correct location." <<endl;
	}
}
void Graphmr::buildGraph(char structure){
	if(error_1){
		cout << "Open the file before building the graph!" <<endl;
		return;
	}

	file >> n_vertices;
	int vx, vy;	// declaration of vertices that constitutes an edge
	float vz;	// declaration of weight if weight = true (weighted graphs)
	n_edges = 0;
	// OBS!!! Alterar para trabalhar com grafos direcionados
	ordDegree.resize(n_vertices);
	Degree = new int[n_vertices];
	Explored = new bool[n_vertices];
	Level = new int[n_vertices];
	Parent = new int[n_vertices];
	Cor = new int[n_vertices];
	bipartidoGroup = new int[n_vertices];
	if(weight == true){
		dist_v = new par_distV[n_vertices];
		set_dist_v();
		cost = new par_cost[n_vertices];
		set_cost();
	}
	set_DELP();
	set_Cor();
	this->structure = structure;
	int n = 1;
	switch(structure){
		case 'm':
			//Adjacency Matrix - False = unweighted graphs (all edges have unit weight)=================
			if(weight == false){
				cout << "Structure: Adjacency Matrix | (unweighted graphs)" <<endl;
				adMatrix = new bool*[n_vertices];
				for (int i=0; i<n_vertices; i++){
					adMatrix[i] = new bool[n_vertices];
					for (int j = 0; j < n_vertices; j++){
						adMatrix[i][j]=false;
					}
				}
			}
			//===========================================================================================
			//Adjacency Matrix - True = weighted graphs =================================================
			else{
				cout << "Structure: Adjacency Matrix | (weighted graphs)" <<endl;
				adMatrix_dir = new float*[n_vertices];
				for (int i=0; i<n_vertices; i++){
					adMatrix_dir[i] = new float[n_vertices];
					for (int j = 0; j < n_vertices; j++){
						adMatrix_dir[i][j]= -1;
					}
				}
			}
			//===========================================================================================
			//Initialization - read file -> build matrix
			if(weight == false){
		        while(file>>vx>>vy){
					if (int(vx) > n_vertices){continue;}
					if (int(vy) > n_vertices){continue;}
					if (int(vx) <= 0){continue;}
					if (int(vy) <= 0){continue;}
					loadPercent(n, n_vertices);
					n++;
		        	n_edges++; 									//counts the number of edges
		            adMatrix[vx-1][vy-1] = true; 				//if vx is connected to vy;
		            if (oriented == false){		            	//non-directed graph
			            adMatrix[vy-1][vx-1] = true; 			//then vy is connected to vx;
			            Degree[vx-1]++, Degree[vy-1]++; 		//increments vx and vy degree's.
			            ordDegree[vx-1]++, ordDegree[vy-1]++;	//-1 because graph file starts at [1] and array starts at [0]
		            }
		            else{										//directed graph
		            	//outDegree[vx-1]++;						//Update output degree
		            	//inDegree[vy-1]++;						//Update input degree
		            }
		        }
				cout << "Graph loaded successfully" << endl;
			}
			else{
		        while(file>>vx>>vy>>vz){
					if (int(vx) > n_vertices){continue;}
					if (int(vy) > n_vertices){continue;}
					if (int(vx) <= 0){continue;}
					if (int(vy) <= 0){continue;}
					if (float(vz) < 0){
						int temp = 1;
						if(temp < 2){
							cout << "Weight < 0 : Does not meet necessary condition (Dijkstra's algorithm)" <<endl;
							//continue;
							temp++;
						}
					}
					loadPercent(n, n_vertices);
					n++;
		        	n_edges++; 									//counts the number of edges
		            adMatrix_dir[vx-1][vy-1] = vz; 				//if vx is connected to vy with weight equal to vz;
		            if (oriented == false){		            	//non-directed graph
			            adMatrix_dir[vy-1][vx-1] = vz; 			//then vy is connected to vx with weight equal to vz;
			            Degree[vx-1]++, Degree[vy-1]++; 		//increments vx and vy degree's.
			            ordDegree[vx-1]++, ordDegree[vy-1]++;	//-1 because graph file starts at [1] and array starts at [0]
		            }
		            else{										//directed graph
		            	//outDegree[vx-1]++;					//Update output degree
		            	//inDegree[vy-1]++;						//Update input degree
		            }
		        }
				cout << "Graph loaded successfully" << endl;
			}
			break;

		case 'l'://Adjacency List
			cout << "Structure: Adjacency List" <<endl;
			adList = new listElement*[n_vertices];
			for (int i = 0; i < n_vertices; i++){
				adList[i] = NULL;
			}

			//===========================================================================================
			//Initialization - read file -> build list
			if(weight == false){
				listElement* tempElement;
				while (file >> vx >> vy){
					if (int(vx) > n_vertices){continue;}
					if (int(vy) > n_vertices){continue;}
					if (int(vx) <= 0){continue;}
					if (int(vy) <= 0){continue;}
					loadPercent(n, n_vertices);
					n++;
		        	n_edges++; 							//counts the number of edges
					tempElement = new listElement(); 	//creates an auxiliary element
					tempElement-> vertex = vy; 			//assigns vy value to the element vertex
					tempElement-> link = adList[vx-1]; 	//pointer to the complementing vertex
					adList[vx-1]	 = tempElement; 	//inserts in the front

					if(oriented == false){//if vx is connected to vy, vy is connected to vx
						tempElement = new listElement(); 	//creates an auxiliary element
						tempElement-> vertex = vx; 			//assigns vx value to the element vertex
						tempElement-> link = adList[vy-1]; 	//pointer to the complementing vertex
						adList[vy-1] = tempElement;
						Degree[vx-1]++, Degree[vy-1]++;
			            ordDegree[vx-1]++, ordDegree[vy-1]++;
					}
					else{
						//nothing
						continue;
					}
				}
				cout << "Graph loaded successfully" << endl;
			}
			else{
				listElement* tempElement;
				while (file >> vx >> vy >> vz){
					if (int(vx) > n_vertices){continue;}
					if (int(vy) > n_vertices){continue;}
					if (int(vx) <= 0){continue;}
					if (int(vy) <= 0){continue;}
					if (float(vz) < 0){
						//cout << "Weight < 0 : Does not meet necessary condition (Dijkstra's algorithm)" <<endl;
						//continue;
					}
					loadPercent(n, n_vertices);
					n++;
		        	n_edges++; 							//counts the number of edges
					tempElement = new listElement(); 	//creates an auxiliary element
					tempElement-> vertex = vy; 			//assigns vy value to the element vertex
					tempElement-> link = adList[vx-1]; 	//pointer to the complementing vertex
					tempElement-> w = vz; 				//assigns vz value to the element w (weight)
					adList[vx-1] = tempElement; 		//inserts in the front

					if(oriented == false){//if vx is connected to vy, vy is connected to vx
						tempElement = new listElement(); 	//creates an auxiliary element
						tempElement-> vertex = vx; 			//assigns vx value to the element vertex
						tempElement-> link = adList[vy-1]; 	//pointer to the complementing vertex
						tempElement-> w = vz; 				//assigns vz value to the element w (weight)
						adList[vy-1] = tempElement;
						Degree[vx-1]++, Degree[vy-1]++;
			            ordDegree[vx-1]++, ordDegree[vy-1]++;
					}
					else{
						//nothing
						continue;
					}
				}
				cout << "Graph loaded successfully" << endl;
			}
			//===========================================================================================
			break;

		case 'v'://Adjacency Vector
			cout << "Structure: Adjacency Vector" <<endl;
			vec.resize(n_vertices);
			if(weight == true){
				vec_W.resize(n_vertices);
			}
			for(int i = 0; i < n_vertices; i++){
		        vec[i] = vector<int>();
		        if(weight == true){
		        	vec_W[i] = vector<float>();
		        }
			}
			//===========================================================================================
			//Initialization - read file -> build vector
			if(weight == false){
				while (file >> vx >> vy){
					if (int(vx) > n_vertices){continue;}
					if (int(vy) > n_vertices){continue;}
					if (int(vx) <= 0){continue;}
					if (int(vy) <= 0){continue;}
					loadPercent(n, n_vertices);
					n++;
					n_edges++;
					vec[vx-1].push_back(vy);
					if(oriented == false){
						vec[vy-1].push_back(vx);
						Degree[vx-1]++, Degree[vy-1]++;
			            ordDegree[vx-1]++, ordDegree[vy-1]++;
					}
					else{
						//nothing
						continue;
					}
				}
				//Sorting the adjacency vectors (Ordenando os vetores de adjacência)
				for (int i = 0; i < n_vertices; i++) {
					sort(vec[i].begin(), vec[i].end());
			    }
				/*Test: Checking Ordering (Teste: verificando ordenação)
			    for (int i = 0; i < n_vertices; i++) {
			        for (int j = 0; j <  Degree[i]; j++){
			            cout << vec[i][j] << " ";
			        }
			        cout << endl;
			    }*/
				cout << "Graph loaded successfully" << endl;
			}
			else{
				while (file >> vx >> vy >> vz){
					if (int(vx) > n_vertices){continue;}
					if (int(vy) > n_vertices){continue;}
					if (int(vx) <= 0){continue;}
					if (int(vy) <= 0){continue;}
					if (float(vz) < 0){
						cout << "Weight < 0 : Does not meet necessary condition (Dijkstra's algorithm)" <<endl;
						//continue;
					}
					loadPercent(n, n_vertices);
					n++;
					n_edges++;
					vec[vx-1].push_back(vy);
					vec_W[vx-1].push_back(vz);
					if(oriented == false){
						vec[vy-1].push_back(vx);
						vec_W[vy-1].push_back(vz);
						Degree[vx-1]++, Degree[vy-1]++;
			            ordDegree[vx-1]++, ordDegree[vy-1]++;
					}
					else{
						//nothing
						continue;
					}
				}
			}
			//===========================================================================================
			break;

		default:
			error_2 = true;
			cout<<"Undefined value, structure: Matrix = 'm', List = 'l', Vector = 'v'."<<endl;
	}
	file.close();
}

void Graphmr::InfoDegree(){
	for(int i = 0; i < n_vertices; i++){
		d_mean+= Degree[i];
		setD_min(Degree[i]);
		setD_max(Degree[i]);
	}
	setD_mean(d_mean/n_vertices);
	setD_median();
}
void Graphmr::BFS(int s){
	queue<int> Q; 			//creates a queue Q that temporarily stores the neighbours
	Parent[s-1] = 0;
	switch(structure){
		case 'm':
			Q.push(s); 		//adds the initial vertex to the queue
			Explored[s-1]=true;
			while (!Q.empty()){
				int vN = Q.front();
				Q.pop();
				//Vertices goes up from 1 to n whereas the array index goes up from 0 to n-1
				for (int i=0; i<n_vertices ;i++){
					if (adMatrix[vN-1][i] == true && Explored[i] == false){
						Q.push(i+1);
						Explored[i] = true;
						Parent[i] = vN;
						Level[i] = Level[vN-1] + 1;
						level_Max = max(level_Max, Level[i]);
					}
				}
			}
			if(print){
				for(int i=0; i<n_vertices; i++){
					for(int j=0; j<n_vertices; j++){
						if(adMatrix[i][j] == true && Level[i]%2 == Level[j]%2){
							set_bipartite(false);
						}
					}
				}
				if(bipartite == true){
					cout<<"Grafo é bipartido!"<<endl;
					for(int i = 0 ; i < n_vertices ; i++){
						if(Level[i]%2 == 0){
					       	bipartidoGroup[i] = 0;
						}
						else{
					       	bipartidoGroup[i] = 1;
						}
					}
				}
				else{
					cout<<"Grafo não é bipartido!"<<endl;
				}
			}
			break;

		case 'l':
			Q.push(s);
			Explored[s-1] = true;
			while (!Q.empty()){
				int vN = Q.front();
				Q.pop();
				for (listElement* i = adList[vN-1]; i!=NULL; i = i->link){
					if (Explored[(i->vertex)-1] == false) {
						Q.push(i->vertex);
						Explored[i->vertex-1] = true;
						Parent[i->vertex-1] = vN;
                    	Level[i->vertex-1] = Level[vN-1] + 1;
						level_Max = max(level_Max, Level[i->vertex-1]);
					}
				}
			}
			if(print){
				for(int i=0; i<n_vertices; i++){
					for(listElement* j = adList[i]; j!=NULL; j = j->link){
						if(Level[i]%2 == Level[j->vertex - 1]%2){
							set_bipartite(false);
						}
					}
				}
				if(bipartite == true){
					cout<<"Grafo é bipartido!"<<endl;
					for(int i = 0 ; i < n_vertices ; i++){
						if(Level[i]%2 == 0){
							bipartidoGroup[i] = 0;
						}
						else{
							bipartidoGroup[i] = 1;
						}
					}
				}
				else{
					cout<<"Grafo não é bipartido!"<<endl;
				}
			}
			break;

		case 'v':
			Q.push(s);
			Explored[s-1] = true;
			while (!Q.empty()){
				int vN = Q.front();
				Q.pop();
				for (int j = 0; j < vec[vN-1].size(); j++) {
					if(Explored[vec[vN-1][j] - 1] == false){
						Q.push(vec[vN-1][j]);
						Explored[vec[vN-1][j] -1] = true;
						Parent[vec[vN-1][j] -1] = vN;
						Level[vec[vN-1][j] -1] = Level[vN-1] + 1;
						level_Max = max(level_Max, Level[vec[vN-1][j] -1]);
					}
				}
			}
			if(print){
				for(int i=0; i<n_vertices; i++){
					for(int j = 0; j < vec[i].size(); j++){
						if(Level[i]%2 == Level[vec[i][j] - 1]%2){
							set_bipartite(false);
						}
					}
				}
				if(bipartite == true){
					cout<<"Grafo é bipartido!"<<endl;
					if(print){
						//Gera um txt que mostra o lado onde cada vértice se encontra dentro de um grafo bipartido
						ofstream output("Bipartite.txt");
						output <<"Vertex\tPart1:"<<endl;
						for(int i = 0 ; i < n_vertices ; i++){
							if(Level[i]%2 == 0){
					        	output<<i+1<<"\t"<<endl;
							}
						}
						output <<"Vertex\tPart2:"<<endl;
						for(int j = 0 ; j < n_vertices ; j++){
							if(Level[j]%2 == 1){
					        	output<<j+1<<"\t"<<endl;
							}
						}
						output.close();
						cout<< "Graph bipartite in: Bipartite.txt "<<endl;
					}
				}
				else{
					cout<<"Grafo não é bipartido!"<<endl;
				}
			}
			break;

		default:
			cout<<"Undefined value, select: Matrix = 'm', List = 'l', Vector = 'v"<<endl;
	}

	if (print){ //set print=true in order to print the spanning tree
		ofstream output("BFS-Tree.txt");
		output <<"Vertex\tParent\tLevel"<<endl;
		for(int i = 0 ; i < n_vertices ; i++){
        	output<<i+1<<"\t"<<Parent[i]<<"\t"<<Level[i]<<endl;
		}
		output.close();
	}
}
void Graphmr::DFS(int s){
	stack<int> S; 		//creates a stack S that temporarily stores the neighbours
	Parent[s-1] = 0;
	switch(structure){
		case 'm':
	        S.push(s);	 //adds the initial vertex to the queue
			while (!S.empty()){
				int vN = S.top();
				S.pop();
				if (Explored[vN-1] == false) { //Vertices goes up from 1 to n whereas the array index goes up from 0 to n-1
					Explored[vN-1] = true;
					for (int i = 0; i < n_vertices; i++){
						if (adMatrix[vN-1][i] == true && Explored[i]==false){
							S.push(i+1);
								Parent[i] = vN;
								Level[i] = Level[vN-1]+1;
						}
					}
				}
			}
			break;

		case 'l': //similar to BFS but using a stack instead of a queue
	        S.push(s);
			while (!S.empty()){
				int vN = S.top();
				S.pop();
				if (Explored[vN-1] == false){
					Explored[vN-1] = true;
					for (listElement* i = adList[vN-1]; i != NULL; i = i->link){
						if (Explored[(i->vertex)-1]==false){
							S.push(i->vertex);
							Parent[(i->vertex)-1] = vN;
							Level[(i->vertex)-1] = Level[vN-1] + 1;
						}
					}
				}
			}
			break;

		case 'v':
			S.push(s);
			Explored[s-1] = true;
			while (!S.empty()){
				int vN = S.top();
				S.pop();
				for (int j = 0; j < vec[vN-1].size(); j++) {
					if(Explored[vec[vN-1][j] - 1] == false){
						S.push(vec[vN-1][j]);
						Explored[vec[vN-1][j] -1] = true;
						Parent[vec[vN-1][j] -1] = vN;
						Level[vec[vN-1][j] -1] = Level[vN-1] + 1;
					}
				}
			}
			break;

		default:
			cout<<"Undefined value, select: Matrix = 'm', List = 'l', Vector = 'v"<<endl;
	}

	if (print){
		ofstream output("DFS-Tree.txt");
		output <<"Vertex\tParent\tLevel"<<endl;
		for(int i=0; i<n_vertices;i++){
            output<<i+1<<"\t"<<Parent[i]<<"\t"<<Level[i]<<endl;
		}
        output.close();
	}
}
void Graphmr::CC(){
	print = false;
	stack<int> cstack;
	queue<int> ccs;
	size = new int[n_vertices];
	int index = 1;
	int offset = 0;
	components = 0;
	cstack.push(1);
	while (!cstack.empty()){
		//cout << "inserido" << endl;
		index = cstack.top();
		cstack.pop();
		BFS(index);
		if (cstack.empty()){
            size[components] = 0;
			for(int i = 0 + offset; i < n_vertices; i++){
				if (Explored[i]==false){
					offset = i;
					cstack.push(i+1);
					break;
				}
				ccs.push(i);
				size[components] = size[components] + 1;
			}
			components++;
			ccs.push(-9999); // Value defined to separate the connect components
		}
	}
	int x;
    ofstream output("Conected Components.txt");
	for(int i = 0; i < components; i++){
             output << "SIZE : " << size[i] <<endl;
             x = ccs.front();
             while(x!= -9999){
            	 output << x<<", ";
            	 ccs.pop();
            	 x = ccs.front();
             }
             ccs.pop();
             output<<endl;
             output<< "====================================================="<<endl;
             }
	output.close();
	cout << "Conected Components: " << components << endl;
}
void Graphmr::Dijkstra(int s){
	priority_queue<par_distV, vector<par_distV>, greater<par_distV> > pq;
	dist_v[s-1].first = 0.0;
	Parent[s-1] = 0;
	switch(structure){
			case 'm':
				pq.push(dist_v[s-1]); 					//adds the initial vertex to the priority queue
				Explored[s-1] = true;
				while(!pq.empty()){ //!pq.empty()
					pair<double, int> top = pq.top(); 	//Obs.: u = top //slide aula 07
					Explored[top.second-1] = true;
					pq.pop();
					//Vertices goes up from 1 to n whereas the array index goes up from 0 to n-1
					for (int i=0; i<n_vertices; i++){
						if (adMatrix_dir[top.second-1][i] != -1 && Explored[i] == false){
							if(dist_v[i].first > dist_v[top.second-1].first + adMatrix_dir[top.second-1][i]){
								dist_v[i].first = double(dist_v[top.second-1].first) + double(adMatrix_dir[top.second-1][i]);
								pq.push(dist_v[i]);
								Parent[i] = dist_v[top.second-1].second;
								Level[i] = Level[dist_v[top.second-1].second-1]+1;
							}
						}
					}
				}
				break;

			case 'l':
				pq.push(dist_v[s-1]); 					//adds the initial vertex to the priority queue
				Explored[s-1] = true;
				while(!pq.empty()){ //!pq.empty()
					pair<double, int> top = pq.top(); 	//Obs.: u = top //slide aula 07
					Explored[top.second-1] = true;
					pq.pop();
					//Vertices goes up from 1 to n whereas the array index goes up from 0 to n-1
					for (listElement* i = adList[top.second -1]; i!=NULL; i = i->link){
						if (Explored[(i->vertex)-1] == false){
							if(dist_v[i->vertex -1].first > dist_v[top.second-1].first + i->w){ //adMatrix_dir[top.second-1][i]
								dist_v[i->vertex - 1].first = dist_v[top.second-1].first + double(i->w);
								pq.push(dist_v[i->vertex - 1]);
								Parent[i->vertex - 1] = dist_v[top.second-1].second;
								Level[i->vertex - 1] = Level[dist_v[top.second-1].second-1]+1;
							}
						}
					}
				}
				break;

			default:
				cout<<"Undefined value, select: Matrix = 'm', List = 'l', Vector = 'v"<<endl;
	}
	if (print){ //set print=true in order to print the spanning tree
		ofstream output("Dijkstra-Tree.txt");
		output <<"Vertex\tParent\tLevel"<<endl;
		for(int i = 0 ; i < n_vertices ; i++){
        	output<<i+1<<"\t"<<Parent[i]<<"\t"<<Level[i]<<endl;
		}
		output.close();
	}
	//cout<< "Dijkstra successfully generated" <<endl;
}
void Graphmr::Prim(int s){
	priority_queue<par_cost, vector<par_cost>, greater<par_cost> > pq;
	cost[s-1].first = 0.0;
	Parent[s-1] = 0;
	switch(structure){
		case 'm':
			pq.push(cost[s-1]); 					//adds the initial vertex to the priority queue
			Explored[s-1] = true;
			while(!pq.empty()){ //!pq.empty()
				pair<double, int> top = pq.top(); 	//Obs.: u = top //slide aula 07
				Explored[top.second-1] = true;
				pq.pop();
				//Vertices goes up from 1 to n whereas the array index goes up from 0 to n-1
				for (int i=0; i<n_vertices; i++){
					if (adMatrix_dir[top.second-1][i] != -1 && Explored[i] == false){
						if(cost[i].first > adMatrix_dir[top.second-1][i]){
							cost[i].first = double(adMatrix_dir[top.second-1][i]);
							Parent[i] = cost[top.second-1].second;
							Level[i] = Level[cost[top.second-1].second-1]+1;
							pq.push(cost[i]); //Se for colocado dentro da fila antes da alteração o resultado será incorreto
						}
					}
				}
			}
			break;

		case 'l':
			pq.push(cost[s-1]); 					//adds the initial vertex to the priority queue
			Explored[s-1] = true;
			while(!pq.empty()){ //!pq.empty()
				pair<double, int> top = pq.top(); 	//Obs.: u = top //slide aula 07
				Explored[top.second-1] = true;
				pq.pop();
				//Vertices goes up from 1 to n whereas the array index goes up from 0 to n-1
				for (listElement* i = adList[top.second -1]; i!=NULL; i = i->link){
					if (Explored[(i->vertex)-1] == false){
						if(cost[i->vertex -1].first > i->w){ //adMatrix_dir[top.second-1][i]
							cost[i->vertex - 1].first = double(i->w);
							Parent[i->vertex - 1] = cost[top.second-1].second;
							Level[i->vertex - 1] = Level[cost[top.second-1].second-1]+1;
							pq.push(cost[i->vertex - 1]);
						}
					}
				}
			}
			break;

		default:
			cout<<"Undefined value, select: Matrix = 'm', List = 'l', Vector = 'v"<<endl;
	}
	if (print){ //set print=true in order to print the spanning tree
		ofstream output("Prim-Tree.txt");
		output << "Custo da MST começando pelo vértice "<< s << " = " << get_MST_cost() <<endl;
		output <<"Vertex\tParent\tLevel"<<endl;
		for(int i = 0 ; i < n_vertices ; i++){
        	output<<i+1<<"\t"<<Parent[i]<<"\t"<<Level[i]<<endl;
		}
		output.close();
		cout<< "Prim successfully generated" <<endl;
	}
}
void Graphmr::FordFulkerson(int s, int t){
	//create a residual graph and fill the residual graph with given capacities
	Explored_b = new bool[n_vertices+2];
	Parent_b = new int[n_vertices+2];
    int u, v;
    int max_flow;
    int path_flow;
    clock_t start, end;
    double time_taken;
	switch(structure){
		case 'm':
			// create residual graph
			rGraph = new int*[n_vertices + 2];
			for (int i = 0; i< n_vertices + 2; i++){
				rGraph[i] = new int[n_vertices + 2];
				for (int j = 0; j < (n_vertices + 2); j++){
					if(i < n_vertices && j < n_vertices){
						if(adMatrix[i][j] == false){
							rGraph[i][j] = 0;
						}
						else{
							rGraph[i][j] = 1;
						}
					}
					else{
						if (i == n_vertices){
							if (j < n_vertices){
								if(bipartidoGroup[j]==0){
									rGraph[i][j] = 1;
									rGraph[j][i] = 1;
								}
								else{
									rGraph[i][j] = 0;
								}
							}
							else{
								rGraph[i][j] = 0;
							}
						}
						else{
							if (j < n_vertices){
								if(bipartidoGroup[j]==1){
									rGraph[i][j] = 1;
									rGraph[j][i] = 1;
								}
								else{
									rGraph[i][j] = 0;
								}
							}
							else{
								rGraph[i][j] = 0;
							}
						}
					}
				}
			}
			//TESTE: Print residual graph
			//for (int i = 0; i<n_vertices + 2; i++){
			//	for(int j = 0; j<n_vertices + 2; j++){
			//		cout<< rGraph[i][j] <<"\t";
			//	}
			//	cout<<endl;
			//}
			max_flow = 0; // There is no flow initially
			start = clock();
		    // Augment the flow while tere is path from source to sink
			while(bfs(s,t)){
				// Find minimum residual capacity of the edges along the
				// path filled by BFS. Or we can say find the maximum flow
				// through the path found.
				path_flow = INT_MAX;
				for(v = t; v != s; v = Parent_b[v-1]){
					u = Parent_b[v-1];
					path_flow = min(path_flow, rGraph[u-1][v-1]);
				}
				// update residual capacities of the edges and reverse edges along the path
				for(v = t; v != s; v = Parent_b[v-1]){
					u = Parent_b[v-1];
					rGraph[u-1][v-1] = rGraph[u-1][v-1] - path_flow;
					rGraph[v-1][u-1] = rGraph[u-1][v-1] + path_flow;
				}
		        // Add path flow to overall flow
		        max_flow += path_flow;
			}
		    // Return the overall flow
			set_maxFlow(max_flow);
	        end = clock();
	        time_taken = double(end - start) / double(CLOCKS_PER_SEC);
	        cout << "Time taken by program is on average: " << time_taken <<endl;
			break;

		case 'l':
			//create residual graph
			adList_rGraph = new listElement*[n_vertices + 2]; //+2 (including vertex s and vertex t)
			for (int i = 0; i < n_vertices+2; i++){
				adList_rGraph[i] = NULL;
			}
			listElement* tempElement;
			for(int i=0; i<n_vertices+2; i++){
				if(i < n_vertices){
					for(listElement* j = adList[i]; j!=NULL; j = j->link){
						if(i < n_vertices){
							tempElement = new listElement(); 		//creates an auxiliary element
							tempElement-> vertex = j->vertex; 			//assigns j value to the element vertex
							tempElement->	w = 1;
							tempElement-> link = adList_rGraph[i]; 	//pointer to the complementing vertex
							adList_rGraph[i] = tempElement; 	//inserts in the front
						}
					}
				}
				else{
					if (i == n_vertices){
						for(int k = 0; k < n_vertices; k++){
							if(bipartidoGroup[k]==0){
								//Ligando vertice s com os vértices do grafo original
								tempElement = new listElement(); 		//creates an auxiliary element
								tempElement-> vertex = k + 1; 			//assigns j value to the element vertex
								tempElement->	w = 1;
								tempElement-> link = adList_rGraph[i]; 	//pointer to the complementing vertex
								adList_rGraph[i] = tempElement; 	//inserts in the front

								/*
								//ligando os vértices do grafo original ao vértice s
								tempElement = new listElement(); 		//creates an auxiliary element
								tempElement-> vertex = i + 1; 			//assigns j value to the element vertex
								tempElement->	w = 1;
								tempElement-> link = adList_rGraph[k]; 	//pointer to the complementing vertex
								adList_rGraph[k] = tempElement; 	//inserts in the front
								*/
							}
						}
					}
					else{
						for(int k = 0; k < n_vertices; k++){
							if(bipartidoGroup[k] != 0){
								/*
								//Ligando vertice t com os vértices do grafo original
								tempElement = new listElement(); 		//creates an auxiliary element
								tempElement-> vertex = k + 1; 			//assigns j value to the element vertex
								tempElement->	w = 1;
								tempElement-> link = adList_rGraph[i]; 	//pointer to the complementing vertex
								adList_rGraph[i] = tempElement; 	//inserts in the front
								*/
								//ligando os vértices do grafo original ao vértice t
								tempElement = new listElement(); 		//creates an auxiliary element
								tempElement-> vertex = i+1; 			//assigns j value to the element vertex
								tempElement->	w = 1;
								tempElement-> link = adList_rGraph[k]; 	//pointer to the complementing vertex
								adList_rGraph[k] = tempElement; 	//inserts in the front

							}
						}
					}
				}
			}
			/*TESTE: Print residual graph
			/////////////////////////////////////////////////////////////////////////////////////////////////
			cout<<"Vetor bipartido: "<<endl;
			for(int i = 0; i < n_vertices; i++){
				cout<< "[" <<i <<"] = " << bipartidoGroup[i]<<endl;
			}
			cout<<"-----------------"<<endl;
			/////////////////////////////////////////////////////////////////////////////////////////////////
			for(int i=0; i<n_vertices; i++){
				cout << "[" <<i <<"] -> ";
				for(listElement* j = adList[i]; j!=NULL; j = j->link){
					cout << j->vertex << "\t";
				}
				cout <<endl;
			}
			cout<<"Residual Graph: "<<endl;
			for(int i=0; i<n_vertices+2; i++){
				cout << "[" <<i <<"] -> ";
				for(listElement* j = adList_rGraph[i]; j!=NULL; j = j->link){
					cout << j->vertex << "|"<<j->w << "\t";
				}
				cout <<endl;
			}
			/////////////////////////////////////////////////////////////////////////////////////////////////
			/*/
			max_flow = 0; // There is no flow initially
		    // Augment the flow while tere is path from source to sink
			//*
	        start = clock();
			while(bfs(s,t)){
				// Find minimum residual capacity of the edges along the
				// path filled by BFS. Or we can say find the maximum flow
				// through the path found.
				path_flow = INT_MAX;
				for(v = t; v != s; v = Parent_b[v-1]){
					u = Parent_b[v-1];
					for(listElement* j = adList_rGraph[u-1]; j!=NULL; j = j->link){
						if(j->vertex == v){
							//path_flow = min(path_flow, rGraph[u-1][v-1]);
							path_flow = min(path_flow, int(j-> w));
						}
					}
				}
				// update residual capacities of the edges and reverse edges along the path
				for(v = t; v != s; v = Parent_b[v-1]){
					u = Parent_b[v-1];
					//rGraph[u-1][v-1] = rGraph[u-1][v-1] - path_flow;
					//rGraph[v-1][u-1] = rGraph[u-1][v-1] + path_flow;
					for(listElement* j = adList_rGraph[u-1]; j!=NULL; j = j->link){
						if(j->vertex == v){
							j-> w = j-> w - path_flow;
						}
					}
					for(listElement* j = adList_rGraph[v-1]; j!=NULL; j = j->link){
						if(j->vertex == u){
							j-> w = j-> w + path_flow;
						}
					}
				}
		        // Add path flow to overall flow
		        max_flow += path_flow;
			}
		    // Return the overall flow
			set_maxFlow(max_flow);
			//*/
	        end = clock();
	        time_taken = double(end - start) / double(CLOCKS_PER_SEC);
	        cout << "Time taken by program is on average: " << time_taken <<endl;
			break;
		case 'v':
			//create residual graph
			break;

		default:
			cout<<"Undefined value, select: Matrix = 'm', List = 'l', Vector = 'v"<<endl;
	}
}
bool Graphmr::bfs(int s, int t){
	set_Parent_b();
	set_Explored_b();
	queue<int> Q; 			//creates a queue Q that temporarily stores the neighbours
	Parent_b[s-1] = 0;
	switch(structure){
		case 'm':
			Q.push(s); 		//adds the initial vertex to the queue
			Explored_b[s-1]=true;
			while (!Q.empty()){
				int vN = Q.front();
				Q.pop();
				//Vertices goes up from 1 to n whereas the array index goes up from 0 to n-1
				for (int i=0; i<n_vertices +2 ;i++){
					if (rGraph[vN-1][i] == 1 && Explored_b[i] == false){
						Q.push(i+1);
						Explored_b[i] = true;
						Parent_b[i] = vN;
					}
				}
			}
			//for (int i = 0; i < n_vertices + 2; i++){
			//	cout<<"explored[" <<i <<"] = " << Explored_b[i] <<endl;
			//}
			// If we reached sink in BFS starting from source, then return true, else false
			return (Explored_b[t-1] == true);
			break;
		case 'l':
			Q.push(s);
			Explored_b[s-1] = true;
			while (!Q.empty()){
				int vN = Q.front();
				Q.pop();
				for (listElement* i = adList_rGraph[vN-1]; i!=NULL; i = i->link){
					if (Explored_b[(i->vertex)-1] == false && i-> w > 0) {
						Q.push(i->vertex);
						Explored_b[i->vertex-1] = true;
						Parent_b[i->vertex-1] = vN;
					}
				}
			}
			return (Explored_b[t-1] == true);
			break;
		default:
			cout<<"Undefined value, select: Matrix = 'm', List = 'l', Vector = 'v"<<endl;
	}
}
void Graphmr::BellmanFord(int t){
	Bellman_dist = new double[n_vertices];
	set_Bellman_dist();
	Bellman_dist[t-1] = 0;
	bool flag = false;
	switch(structure){
		case 'm':
			break;
		case 'l':
			for (int i = 0; i < n_vertices - 1; i++){
				for(int v = 0; v < n_vertices; v++){
					for(listElement* j = adList[v]; j!=NULL; j = j->link){
						if(Bellman_dist[v] > Bellman_dist[j->vertex - 1] + j-> w){
							Bellman_dist[v] = Bellman_dist[j->vertex - 1] + (j-> w);
							flag = true;
						}
					}
				}
				if(flag==false){
					break;
				}
				flag = false;
			}
			//detecting negative cycles
			for(int v = 1; v < n_vertices; v++){
			  	for(listElement* j = adList[v]; j!=NULL; j = j->link){
			  		if(Bellman_dist[v] > Bellman_dist[j->vertex - 1] + j-> w){
			  			cout << "Negative Cycle Detected!"<<endl;
			  			ciclo_bellman = true;
			  			return;
			  		}
				}
			}
			ciclo_bellman = false;
  			cout << "No negative Cycle Detected!"<<endl;
			break;
		case 'v':
			break;
		default:
			cout<<"Undefined value, select: Matrix = 'm', List = 'l', Vector = 'v"<<endl;
	}
}
void Graphmr::runGraph(string path, char structure, char search, int v_init, bool info, bool print){
	this->print = print;
	openFile(path);
	if (error_1 == true){
		return;
	}
	buildGraph(structure);
	if (error_2 == true){
		return;
	}
	if (info == true){
		InfoDegree();
		cout<<"****************************************"<<endl;
		cout<<"Vertices:" 		<<"\t"<<getN_vertices()	<<endl;
		cout<<"Edges:"			<<"\t\t"<<getN_edges()	<<endl;
		cout<<"Degree(mean):" 	<<"\t"<<getD_mean()		<<endl;
		cout<<"Degree(min):" 	<<"\t"<<getD_min()		<<endl;
		cout<<"Degree(max):" 	<<"\t"<<getD_max()		<<endl;
		cout<<"Degree(median):" <<"\t"<<getD_median()	<<endl;
		cout<<"****************************************"<<endl;
	}
	time (&begin); // note time before execution
	switch(search){
		case 'b':
			cout<< "BFS started" <<endl;
			BFS(v_init);
			cout<< "BFS successfully generated" <<endl;
			break;
		case 'd':
			DFS(v_init);
			cout<< "DFS successfully generated" <<endl;
			break;
		default:
			cout<<"Undefined value, search: BFS = 'b', DFS = 'd'."<<endl;
	}
	time (&end); // note time after execution
	double difference = difftime (end,begin);
	cout<<"time taken (search): " << difference << " seconds." <<endl;
}

//Other Functions*************************************
void  Graphmr::loadPercent(int p, int n){
	if (p == 1){cout << "***Loading***"<<endl;}
	if (p == n) {cout << "**********100%"<<endl;}
	else if (p == 8*n/10) {cout << "********  80%"<<endl;}
	else if (p == 6*n/10) {cout << "******    60%"<<endl;}
	else if (p == 4*n/10) {cout << "****      40%"<<endl;}
	else if (p == 2*n/10) {cout << "**        20%"<<endl;}
}

