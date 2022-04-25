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
    }
    int vertices;
    void print();
    void add_edge(int, int);
    bool findPath(int, int);
};

void graph::print()
{
    for (int i = 1; i < 7; ++i)
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

bool graph::findPath(int u, int v)
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

int main()
{
    graph go(7);

    go.add_edge(1, 2);
    go.add_edge(1, 4);

    go.add_edge(2, 5);

    go.add_edge(3, 5);
    go.add_edge(3, 6);

    go.add_edge(4, 2);

    go.add_edge(5, 4);

    go.add_edge(6, 6);

    go.print();

    std::cout << "path exists " << std::boolalpha << go.findPath(6, 1) << std::endl;

    return 0;
}