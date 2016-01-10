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

int main(void) {
	bool **graph = generate_graph();
	print_graph(graph);

	return 0;
}
