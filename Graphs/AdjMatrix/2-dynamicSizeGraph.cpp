/*
This Graph will use dynamic input for matrix _size

@implements:

>function() pathFinder
-> checks if path exists from one node to the other
*/

#include <iostream>

class Graph
{
private:
    void _initGraphwithFalse();
    void _initGraph();
    void _sizeInput();

    bool *_visited;
    int _size;

public:
    Graph()
    {
        _sizeInput();
        _initGraph();
        _initGraphwithFalse();
    }

    ~Graph()
    {
        delete[] _visited;
        delete[] matGraph;
        std::cout << "\nreleased the newly allocated memory\n";
    }

    bool **matGraph;
    void print();
};

void Graph::_initGraph()
{
    matGraph = new bool *[_size];
    for (int i = 0; i < _size; ++i)
    {
        matGraph[i] = new bool[_size];
    }
    // here we got a 2d array in place now
    _visited = new bool[_size];
}

void Graph::_sizeInput()
{
    std::cout << "_size of Graph should be? tell us the length only :";
    std::cin >> _size;
    std::cout << std::endl;
}

void Graph::print()
{
    for (int row = 0; row < 4; row++)
    {
        for (int col = 0; col < 4; col++)
        {
            std::cout << matGraph[row][col] << " ";
        }
        std::cout << std::endl;
    }
}

void Graph::_initGraphwithFalse()
{
    for (int row = 0; row < 4; row++)
    {
        std::fill(matGraph[row], matGraph[row] + 4, false);
    }
}

int main()
{
    Graph obj;

    obj.matGraph[0][1] = true;
    obj.matGraph[1][2] = true;
    obj.matGraph[2][0] = true;
    obj.matGraph[3][2] = true;

    obj.print();

    return 0;
}