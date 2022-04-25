#include <iostream>
#include <vector>
#include <list>
#include <iterator>
#include <queue>

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
        for (int i = 0; i < vertices; ++i)
        {
            visited[i] = false;
        }
    }

    int vertices;
    bool *visited;

    void add_edge(int, int);
    void BFS(int);
    void print();
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

void graph::BFS(int source)
{
    std::queue<int> Q;
    visited[source] = true;
    Q.emplace(source);

    while (!Q.empty())
    {
        // if (visited[] == true)
        //   continue;
        int top = Q.front();
        Q.pop();
        std::cout << "visiting " << top << std::endl;
        visited[top] = true;

        for (std::list<int>::iterator it = adjacencyList[top].begin(); it != adjacencyList[top].end(); ++it)
        {
            if (visited[*it] != true)
            {
                Q.push(*it);
                // DFS(*it);
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