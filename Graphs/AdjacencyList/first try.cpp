#include <iostream>
#include <vector>
/*
kept pointers in vector to avoid copy by value
*/
struct adjListNode
{
    int vertex;
    adjListNode *neighbour;

    adjListNode(int x) : vertex(x), neighbour(nullptr)
    {
    }
};

int main()
{
    std::vector<adjListNode *> AdjacencyList;
    // AdjacencyList

    AdjacencyList.push_back(new adjListNode(0));
    AdjacencyList.push_back(new adjListNode(1));
    AdjacencyList.push_back(new adjListNode(2));
    AdjacencyList.push_back(new adjListNode(3));
    AdjacencyList.push_back(new adjListNode(4));
    AdjacencyList.push_back(new adjListNode(5));
    AdjacencyList.push_back(new adjListNode(6));

    for (int i = 0; i < 7; ++i)
        std::cout << AdjacencyList.at(i)->vertex << std::endl;

    // add neighbours for each
    AdjacencyList.at(0)->neighbour = new adjListNode(1);
    AdjacencyList.at(1)->neighbour = new adjListNode(2);
    AdjacencyList.at(2)->neighbour = new adjListNode(0);
    AdjacencyList.at(3)->neighbour = new adjListNode(2);
    AdjacencyList.at(4)->neighbour = new adjListNode(6);
    AdjacencyList.at(5)->neighbour = new adjListNode(4);
    AdjacencyList.at(6)->neighbour = new adjListNode(5);

    // traversing each vertex's neighbour
    for (int i = 0; i < 7; ++i)
    {
        std::cout << AdjacencyList.at(i)->vertex << " : "; //
        adjListNode *neighbourPtr = AdjacencyList.at(i)->neighbour;

        while (neighbourPtr != nullptr)
        {
            std::cout << neighbourPtr->vertex << ",";
            neighbourPtr = neighbourPtr->neighbour;
        }
        std::cout << std::endl;
    }

    return 0;
}