#include <iostream>
#include <list>
#include <iterator>
#include <queue>

/*
1-> implement Graph using array of list

2-> shortest path usig BFS
*/

struct Graph
{
public:
	typedef int node_t;
	typedef std::list<node_t> graph_t;

protected:
	graph_t *_graph;
	node_t vertices;

public:
	void
	print();

	void
	add_edge(int, int);

	Graph(int v) : vertices(v)
	{
		_graph = new graph_t[vertices];
	}

	~Graph()
	{
		delete[] _graph;
	}
};

void Graph::print()
{
	for (int each_node = 0; each_node < vertices; ++each_node)
	{
		std::cout << "vertex : " << each_node << " : ";
		{
			std::cout << "[ ";

			for (auto neighbrs = _graph[each_node].begin(); neighbrs != _graph[each_node].end(); ++neighbrs)
			{
				std::cout << *neighbrs << ", ";
			}

			std::cout << " ]" << std::endl;
		}
	}
}

void Graph::add_edge(int u, int v)
{
	_graph[u].push_back(v);
	_graph[v].push_back(u);
}

struct Solution : public Graph
{
	Solution(int V) : Graph(V)
	{
		visited.resize(V);
	};

	std::vector<bool> visited;

	int shortest_path(int, int);
};

int Solution::shortest_path(int src, int target)
{
	if (src == target)
		return 0;

	std::fill(visited.begin(), visited.end(), false);
	int node, distance;

	std::queue<std::pair<int, int>> queue;
	queue.push({src, 0});

	while (!queue.empty())
	{
		std::pair<int, int> tmp = queue.front();
		queue.pop();

		node = tmp.first;
		distance = tmp.second;

		if (node == target)
			return distance;

		if (visited[node])
			continue;

		visited[node] = true;

		for (auto neighbours = _graph[node].begin(); neighbours != _graph[node].end(); ++neighbours)
		{
			queue.push({*neighbours, distance + 1});
		}
	}
	return -1;
}

int main()
{
	Solution go(6);

	go.add_edge(0, 1);
	go.add_edge(0, 4);
	// go.add_edge(0, 3); // BYPASS
	go.add_edge(1, 2);
	go.add_edge(2, 3);
	go.add_edge(3, 4);

	go.print();

	std::cout << go.shortest_path(0, 4) << "\n";

	return 0;
}