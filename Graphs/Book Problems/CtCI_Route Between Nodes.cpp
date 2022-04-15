#include <iostream>
/*
#implements:

>function() pathFinder
-> checks if path exists from one node to the other

to refer complete code for this file, refer AdjMatrix -> staticSizeGraph.cpp
*/
#define DEBUG false

class graph
{
private:
public:
    bool matGraph[4][4];
    bool visited[4];
    void initGraphwithFalse();
    void print();
    bool pathFinder(int source, int target);
    graph()
    {
        initGraphwithFalse();
    }
};


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