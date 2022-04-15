#include <iostream>

struct t_Node
{
    int node_data;
    t_Node *left;
    t_Node *right;
    t_Node(int newdata) : node_data(newdata), left(nullptr), right(nullptr) {}
};

class tree
{
private:
    t_Node *root;

public:
    tree()
    {
        // root = nullptr;
    }
    void insert(int);
};

void tree::insert(int newdata)
{
    t_Node *tmp = new t_Node(newdata);
    
}

int main()
{

    return 0;
}