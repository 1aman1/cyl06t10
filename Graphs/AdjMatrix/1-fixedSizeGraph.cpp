/*
This Graph uses fixed size matrix

#implements:

>function() pathFinder
-> checks if path exists from one node to the other
*/
#include <iostream>

class Graph
{
private:
    void initGraphwithFalse();

public:
    Graph()
    {
        initGraphwithFalse();
    }
    
    bool matGraph[4][4];
    void print();
};

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

void Graph::initGraphwithFalse()
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