#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <map>
#include <bitset>
#include <list>
#include <climits>

using namespace std;

struct node
{
	node(int data) : data(data), min(data){};
	int min;
	int data;
};

class MinStack
{
	std::vector<node> stack;

public:
	MinStack() {}

	void push(int val)
	{
		node newNode(val);
		if (!stack.empty())
		{
			newNode.min = std::min(val, getMin());
		}
		stack.push_back(newNode);
	}

	void pop()
	{
		stack.pop_back();
	}

	int top()
	{
		return stack.back().data;
	}

	int getMin()
	{
		return stack.back().min;
	}
};

int main()
{
	MinStack *obj = new MinStack();
	obj->push(-2);
	obj->push(0);
	obj->push(-1);
	std::cout << obj->getMin();
	std::cout << obj->top();
	obj->pop();
	std::cout << obj->getMin();

	return 0;
}