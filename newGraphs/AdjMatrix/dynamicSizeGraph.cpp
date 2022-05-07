/*
This graph will use dynamic input for matrix size

@implements:

>function() pathFinder
-> checks if path exists from one node to the other
*/

#include <iostream>

#define DEBUG false

class graph
{
private:
public:
    int size;
    bool **matGraph;
    bool *visited;
    // make attributes private

    void initGraphwithFalse();
    void print();
    void initGraph();
    void sizeInput();
    graph()
    {
        sizeInput();
        initGraph();
        initGraphwithFalse();
    }
    ~graph()
    {
        delete[] visited;
        delete[] matGraph;
        std::cout << "\ndeleted the dynamic memory allocated\n";
    }
};

void graph::initGraph()
{
    matGraph = new bool *[size];
    for (int i = 0; i < size; ++i)
    {
        matGraph[i] = new bool[size];
    }
    // here we got a 2d array in place now
    visited = new bool[size];
}

void graph::sizeInput()
{
    std::cout << "size of graph should be? tell us the length only :";
    std::cin >> size;
    std::cout << std::endl;
}

void graph::print()
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

void graph::initGraphwithFalse()
{
    for (int row = 0; row < 4; row++)
    {
        for (int col = 0; col < 4; col++)
        {
            matGraph[row][col] = false;
        }
        std::cout << std::endl;
    }
}

int main()
{
    graph obj;

    obj.matGraph[0][1] = true;
    obj.matGraph[1][2] = true;
    obj.matGraph[2][0] = true;
    obj.matGraph[3][2] = true;

    obj.print();

    return 0;
}