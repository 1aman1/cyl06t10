#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <map>
#include <bitset>
#include <stack>
#include <list>
#include <climits>

using namespace std;

class MinStack
{
public:
	void push(int x)
	{
		if (myStack.empty())
			myStack.emplace(x, x);
		else
			myStack.emplace(x, min(x, myStack.top().second));
	}

	void pop()
	{
		myStack.pop();
	}

	int top()
	{
		return myStack.top().first;
	}

	int getMin()
	{
		return myStack.top().second;
	}

private:
	stack<pair<int, int>> myStack; // {x, min}
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