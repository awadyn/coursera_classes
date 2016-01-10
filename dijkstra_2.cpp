#include <iostream>
#include <cstdlib>
#include <ctime>
const int graph_size = 5;

inline double prob() {
	 return ((static_cast<double>(rand() * 100))/100);
}

bool** generate_graph(void) {
	bool **graph;
	srand(clock());
	//create a two dimensional array whose base pointer is 'graph'
	graph = new bool*[graph_size];
	for (int i = 0; i < graph_size; i ++) {
		graph[i] = new bool[graph_size];
	}
	//fill graph based on density
	//density: probability that an edge exists
	for (int i = 0; i < graph_size; i ++) {
		for (int j = i; j < graph_size; j ++) {
			if (i == j)
				graph[i][j] = false;
			else
				graph[i][j] = graph[j][i] = (prob() < 0.19);
		}
	}
	return graph;
}

void print_graph (bool **graph) {
	for (int i = 0; i < graph_size; i ++) {
		for (int j = 0; j < graph_size; j ++) {
			std::cout << graph[i][j] << " ";
		}
		std::cout << '\n';
	}
}

bool is_connected(bool **graph) {
	bool closed[graph_size], open[graph_size];
	int closed_nodes = 0;
	int old_closed_nodes = 0;
	for (int i = 0; i < graph_size; i ++)
		closed[i] = open[i] = false;
	open[0] = true;

	while (closed_nodes < graph_size) {
		old_closed_nodes = closed_nodes;
		//add node from open set to closed set
		//fill open set with other nodes
		for(int i = 0; i < graph_size; i ++) {
			if ((open[i] == true) && (closed[i] == false)) {
				closed[i] = true;
				closed_nodes ++;
				for (int j = 0; j < graph_size; j ++)
					open[j] = open[j] || graph[i][j];
			}
		}
		//when no nodes found in open set
		if (old_closed_nodes == closed_nodes) break;
	}
	if (closed_nodes == graph_size) return true;
	else if (old_closed_nodes == closed_nodes) return false;
}

int main(void) {
	bool **graph = generate_graph();
	print_graph(graph);
	std::cout << is_connected(graph) << '\n';

	return 0;
}
