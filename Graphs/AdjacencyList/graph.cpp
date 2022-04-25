#include <iostream>
#include <vector>
#include <list>
#include <iterator>

/*
implement graph,

use a vector of lists

then a function to check if path exists or not
*/

/* TO EXECUTE 
 https://www.tutorialspoint.com/compile_cpp_online.php
*/


struct graph
{
    std::vector<std::list<int>> adjacencyList;
    graph(int s) : size(s)
    {
        adjacencyList.reserve(size);
    }
    int size;
    void print();
    void add_edge(int, int);
};

void graph::print()
{
    for (int i = 1; i < 5; ++i)
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
    std::cout << u << " : " << v << std::endl;
    adjacencyList[u].push_back(v);
}

/* TO EXECUTE 
 https://www.tutorialspoint.com/compile_cpp_online.php
*/


int main()
{
    graph go(7);
    std::cout << " obj create" << std::endl;
    go.add_edge(1, 2);

    std::cout << " add edge" << std::endl;
    
    go.add_edge(1, 4);

    go.add_edge(2, 5);

    go.add_edge(3, 5);
    go.add_edge(3, 6);

    go.add_edge(4, 2);

    go.add_edge(5, 4);

    go.add_edge(6, 6);

    go.print();

    return 0;
}