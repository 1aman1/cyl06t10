#include <iostream>
#include <list>
#include <iterator>
#include <queue>

/*
1-> implement Graph using array of list

2-> count connected components
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
	_graph[v].push_back(u);
}

struct Solution : public Graph
{
	Solution(int V) : Graph(V)
	{
		visited.resize(V);
	};

	std::vector<bool> visited;

	int count_connected_components();

	void depth_first_search_recursive(int);
};

void Solution::depth_first_search_recursive(int src = 0)
{
	if (!visited[src])
	{
		visited[src] = true;

		for (auto itr = _graph[src].begin(); itr != _graph[src].end(); ++itr)
		{
			depth_first_search_recursive(*itr);
		}
	}
}

int Solution::count_connected_components()
{
	int count = 0;
	for (size_t i = 0; i < visited.size(); ++i)
	{
		if (!visited[i])
		{
			depth_first_search_recursive(i);
			++count;
		}
	}
	return count;
}

int main()
{
	Solution go(9);

	/* 	go.add_edge(0, 1);
		go.add_edge(3, 5);
		go.add_edge(4, 5);
		go.add_edge(5, 6);
		go.add_edge(5, 7);
	 */

	go.add_edge(0, 8);
	go.add_edge(0, 1);
	go.add_edge(0, 5);
	go.add_edge(2, 3);
	go.add_edge(2, 4);
	go.add_edge(3, 4);
	go.add_edge(5, 8);

	go.print();

	std::cout << go.count_connected_components()
			  << "\n";

	return 0;
}