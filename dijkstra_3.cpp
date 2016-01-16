#include <iostream>
#include <vector>

inline double prob() {
	return ((static_cast<double>(rand() * 100))/100);
}

template<typename T>
inline std::ostream& operator<<(std::ostream& out, const std::vector<T> &v) {
	std::cout << "<";
	char separate[3] = {'\0', ' ', '\0'};
	for (const auto& i : v) {
		std::cout << separate << i;
		separate[0] = ',';
	}
	std::cout << ">\n";
	return out;
} 

template<typename T>
inline std::ostream& operator<<(std::ostream& out, const std::vector<std::vector<T>> &v) {
	char separate[2] = {' ', '\0'};
	for (const auto& i : v) {
		std::cout << '|';
		for (const auto& j: i)
			std::cout << separate << j;
		std::cout << " |\n";
	}
}

std::vector<std::vector<bool>> generate_graph(const int num_nodes) {
	srand(clock());
	std::vector<std::vector<bool>> graph(num_nodes, std::vector<bool>(num_nodes));
	for (int i = 0; i < num_nodes; i ++) {
		for (int j = 0; j < num_nodes; j ++) {
			if (i == j)
				graph[i][j] = false;
			else
				graph[i][j] = graph[j][i] = (prob() < 0.19);
		}
	}
	return graph;
}

bool is_connected(std::vector<std::vector<bool>> &graph) {
	size_t size = graph.size();
	std::vector<bool> closed(size, 0);
	std::vector<bool> open(size, 0);
	int old_closed_nodes = 0, closed_nodes = 0;
	open[0] = true;
	while (closed_nodes < size) {
		old_closed_nodes = closed_nodes;
		for (int i = 0; i < size; i ++) {
			if ((open[i] == true) && (closed[i] == false)) {
				closed[i] = true;
				closed_nodes ++;
				for (int j = 0; j < size; j ++) {
					open[j] = open[j] || graph[i][j];
				}
			}
		}
		if (old_closed_nodes == closed_nodes) break;
	}
	if (closed_nodes == size) return true;
	else if (old_closed_nodes == closed_nodes) return false;
}

int main(void) {

	std::vector<bool> a(5, 0);
	std::cout << "a: " << a << '\n';
	srand(clock());
	for (std::vector<bool>::iterator itr = a.begin(); itr < a.end(); itr ++) {
		*itr = (prob() < 0.19);
	}
/*	std::cout << "a: " << a << '\n';
	std::vector<std::vector<bool>> c(5, std::vector<bool>(5, 0));
	for(std::vector<std::vector<bool>>::iterator itr = c.begin(); itr < c.end(); itr ++) {
		for (std::vector<bool>::iterator itr_2 = (*itr).begin(); itr_2 < (*itr).end(); itr_2 ++) {
			(*itr_2) = (prob() < 0.19);
		}
	}
	std::cout << c << '\n';
	std::cout << c[1][1] << '\n';
*/
	std::cout << generate_graph(5);
	std::cout << generate_graph(6).size() << '\n';
	std::vector<std::vector<bool>> graph = generate_graph(5);
	std::cout << graph;
	std::cout << is_connected(graph) << '\n';
/*
	int nums[4] = {16, 17, 18, 19};
	std::vector<int> b(nums, nums + (sizeof(nums)/sizeof(int)));
	for(std::vector<int>::iterator it = b.begin(); it != b.end(); it ++)
		std::cout << *it << " ";
	std::cout << '\n';
*/
	return 0;
}
