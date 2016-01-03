#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

const int num_nodes = 5;

int main(void) {

	srand(clock());

	int **a = new int*[num_nodes * sizeof(int *)];
	for (int i = 0 ; i < num_nodes; i ++) {
		a[i] = new int[num_nodes * sizeof(int)];
	}
	cout << "Graph, " << num_nodes << " nodes: " << endl;
	for (int i = 0; i < num_nodes; i ++) {
		for (int j = 0; j < num_nodes; j ++) {
			if (i == j)
				a[i][j] = 0;
			else
				a[i][j] = (rand() % 10);
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	int source = (rand() % num_nodes);
	int destination = (rand() % num_nodes);
	cout << endl << "source = " << source << endl;
	cout << "destination = " << destination << endl << endl;


	int *closed_set = new int[num_nodes * sizeof(int)];
	for (int i = 0; i < num_nodes; i ++) {
		closed_set[i] = 0;
	}
	int *open_set = new int[num_nodes * sizeof(int)];
	for (int i = 0; i < num_nodes; i ++) {
		open_set[i] = 0;
	}


	int least_node = source;
	int cost = 0;

	while (1) {
                cout << "open set:" << endl;
                for (int i = 0; i < num_nodes; i ++) {
                        cout << open_set[i] << " ";
                }
                cout << endl;
                cout << "closed set:" << endl;
                for (int i = 0; i < num_nodes; i ++) {
                        cout << closed_set[i] << " ";
                }
                cout << endl;
		cout << "least_node = " << least_node << endl;
		if (least_node == destination)
			break;

		int min_cost = 9;
		int min_index;
		for (int i = 0; i < num_nodes; i ++) {
			if (least_node != i) {
				if (a[least_node][i] != 0) {
					if (closed_set[i] == 0) { // not in closed set
						if (open_set[i] == 0) { // not in open set
							open_set[i] = a[least_node][i];
							if (open_set[i] < min_cost) {
								min_cost = open_set[i];
								min_index = i;
							}
						}
						else { // in open set
							if (open_set[i] > a[least_node][i])
								open_set[i] = a[least_node][i];
							if (open_set[i] < min_cost) {
								min_cost = open_set[i];
								min_index = i;
							}
						}
					}
				}
			}
		}
		least_node = min_index;
		closed_set[least_node] = open_set[least_node] + cost;
		cost += open_set[least_node];
	}
	cout << "cost = " << cost << endl;

	return 0;
}
