class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &temperatures)
    {
        int SIZE = temperatures.size();

        stack<pair<int, int>> myStack;
        vector<int> result(SIZE);

        for (int i = 0; i < SIZE; ++i)
        {
            int currDay = i;
            int currTemp = temperatures[i];

            while (!myStack.empty() && currTemp > myStack.top().second)
            {
                int prevDay = myStack.top().first;
                int prevTemp = myStack.top().second;
                myStack.pop();

                result[prevDay] = currDay - prevDay;
            }
            myStack.push({currDay, currTemp});
        }
        return result;
    }
};