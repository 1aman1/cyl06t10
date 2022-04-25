#include <iostream>
#include <vector>
#include <list>
#include <iterator>

/*
implement graph,

use a vector of lists

then a function to check if path exists or not
*/

struct graph
{
    std::list<int> *adjacencyList;
    graph(int v) : vertices(v)
    {
        adjacencyList = new std::list<int>[vertices];
        visited = new bool[vertices];
    }
    int vertices;
    bool *visited;
    void print();
    void add_edge(int, int);
    bool pathExists(int, int);
    void DFS(int);
};

void graph::print()
{
    for (int i = 0; i < vertices; ++i)
    {
        std::cout << "vertex :" << i << " : ";
        {
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
    adjacencyList[u].push_back(v);
}

bool graph::pathExists(int u, int v)
{
    if (adjacencyList[u].empty())
        return false;
    for (std::list<int>::iterator it = adjacencyList[u].begin(); it != adjacencyList[u].end(); ++it)
    {
        if (*it == v)
            return true;
    }

    return false;
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

    for (int i = 0; i < go.vertices; ++i)
    {
        go.visited[i] = false;
    }

    go.DFS(0);

    return 0;
}