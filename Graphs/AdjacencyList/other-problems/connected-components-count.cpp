#include <iostream>
#include <list>
#include <iterator>
#include <queue>

/*
1-> implement Graph using array of list

2-> Breadth first search
*/

struct Graph
{
public:
	typedef int node;
	typedef std::list<node> graph_t;

protected:
	graph_t *_graph;
	node vertices;

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
}

struct HasPath : public Graph
{
	HasPath(int V) : Graph(V)
	{
		visited.resize(V);
	};

	std::vector<bool> visited;

	bool has_path_DFS(int, int);

	bool has_path_BFS(int, int);
};

bool HasPath::has_path_BFS(int source, int target)
{
	if (source == target)
		return true;

	std::queue<node> queue;

	queue.push(source);
	visited[source] = true;

	while (!queue.empty())
	{
		int curr_node = queue.front();
		visited[curr_node] = true;
		queue.pop();

		for (auto neighbrs = _graph[curr_node].begin(); neighbrs != _graph[curr_node].end(); ++neighbrs)
		{
			if (*neighbrs == target)
				return true;

			if (!visited[*neighbrs])
				queue.push(*neighbrs);
		}
	}
	return false;
}

bool HasPath::has_path_DFS(int source, int target)
{
	if (!visited[source])
	{
		if (source == target)
			return true;

		visited[source] = true;

		for (auto neighbrs = _graph[source].begin(); neighbrs != _graph[source].end(); ++neighbrs)
		{
			if (has_path_DFS(*neighbrs, target))
				return true;
		}
	}
	return false;
}

int main()
{
	HasPath go(6);
	/*
		go.add_edge(0, 1);
		go.add_edge(0, 2);
		go.add_edge(2, 4);
		go.add_edge(1, 3);
		go.add_edge(3, 5); */

	go.add_edge(0, 1);
	go.add_edge(0, 4);
	go.add_edge(0, 5);
	go.add_edge(1, 3);
	go.add_edge(1, 4);
	go.add_edge(2, 1);
	go.add_edge(3, 2);
	go.add_edge(3, 4);

	go.print();

	if (go.has_path_BFS(1, 4))
		std::cout << "Yes\n";
	else
		std::cout << "No\n";

	return 0;
}