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
    bool pathFinder(int source, int target);
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

bool graph::pathFinder(int source, int target)
{
    if (visited[source] != true)
    {
        visited[source] = true;

        if (DEBUG)
            std::cout << " :checking node: " << source << std::endl;
        for (int col = 0; col < 4; ++col)
        {
            if (DEBUG)
                std::cout << __LINE__ << " :  from: " << source << " :to: " << col << std::endl;

            if (matGraph[source][col] == true)
            {
                if (DEBUG)
                    std::cout << __LINE__ << " :   edge between:" << source << ":" << col << std::endl;

                // path exists
                if (col == target)
                    return true;

                if (DEBUG)
                    std::cout << __LINE__ << ":    going to check between:" << col << ":" << target << std::endl;

                return pathFinder(col, target);
            }
        }
        // path doesn't exist
        return false;
    }
    else
    { // path doesn't exist
        if (DEBUG)
            std::cout << " Already visited \n";
        return false;
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

    std::cout << std::endl;
    int source, target;
    
    source = 0, target = 2;
    std::cout << source << " is connected with " << target << " ? "
              << std::boolalpha
              << obj.pathFinder(source, target);

    std::cout << std::endl;
    return 0;
}