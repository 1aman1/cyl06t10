/*
This graph uses fixed size matrix

#implements:

>function() pathFinder
-> checks if path exists from one node to the other
*/
#include <iostream>

#define DEBUG false

class graph
{
private:
public:
    bool matGraph[4][4];
    bool visited[4];
    void initGraphwithFalse();
    void print();
    graph()
    {
        initGraphwithFalse();
    }
};

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