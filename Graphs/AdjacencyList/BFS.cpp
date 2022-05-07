#include <iostream>
#include <list>
#include <iterator>
#include <queue>

/*
1-> implement graph using array of list

2-> a function for BFS traversal
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
		for (int i = 0; i < vertices; ++i)
		{
			visited[i] = false;
		}
	}

	void print();
	void add_edge(int, int);

	// BFS utility
	bool *visited;
	void BFS(int);
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

void graph::BFS(int source)
{
	std::queue<int> Q;

	Q.emplace(source);
	while (!Q.empty())
	{
		int top = Q.front();
		Q.pop();

		std::cout << "visiting " << top << std::endl;
		visited[top] = true;

		for (std::list<int>::iterator it = adjacencyList[top].begin(); it != adjacencyList[top].end(); ++it)
		{
			if (visited[*it] != true)
			{
				visited[*it] = true;
				Q.push(*it);
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

	go.BFS(0);

	return 0;
}