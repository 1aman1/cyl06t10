#include <iostream>
#include <list>
#include <iterator>
#include <vector>

/*
1-> implement graph using array of list

2-> a function for DFS traversal
*/

struct graph
{
	// graph utility
	std::list<int> *adjacencyList;
	int vertices;

	graph(int v) : vertices(v)
	{
		adjacencyList = new std::list<int>[vertices];

		visited = new bool[vertices];
		for (int i = 0; i < vertices; ++i) { visited[i] = false; }
	}

	void add_edge(int, int);
	void print();

	// DFS utility
	bool *visited;
	void DFS(int);
};

void graph::print()
{
	for (int i = 0; i < vertices; ++i)
	{
		std::cout << "vertex :" << i << " : ";
		{
			// traverse neighbour for the current vertex
			std::list<int>::iterator it;
			for (it = adjacencyList[i].begin(); it != adjacencyList[i].end(); ++it)
			{
				std::cout << *it << ", ";
			}
			std::cout << std::endl;
		}
	}
}

void graph::add_edge(int u, int v)
{
	// undirected graph
	adjacencyList[u].push_back(v);

	// directed graph
	// adjacencyList[v].push_back(u);
}

void graph::DFS(int source)
{
	for (int i = source; i < vertices; ++i)
	{
		if (visited[i] == true)
			continue;
		std::cout << "visiting " << i << std::endl;
		visited[i] = true;
		for (std::list<int>::iterator it = adjacencyList[i].begin(); it != adjacencyList[i].end(); ++it)
		{
			if (visited[*it] != true)
			{
				DFS(*it);
			}
		}
	}
}

int main()
{
	graph go(6);

	go.add_edge(0, 1);
	go.add_edge(0, 4);
	go.add_edge(0, 5);

	go.add_edge(1, 3);
	go.add_edge(1, 4);

	go.add_edge(2, 1);

	go.add_edge(3, 2);
	go.add_edge(3, 4);

	go.print();

	go.DFS(0);

	return 0;
}