#include <iostream>
#include <vector>
class method
{
    std::vector<int> array;

public:
    void push_back(int val)
    {
        array.push_back(val);
    }

    void printArray()
    {
        for (auto i : array)
            std::cout << i << " ";
        std::cout << std::endl;
    }

    int maxSubArray_bruteForce(int k)
    {
        if (k == 0 || k > array.size())
            return -1;

        int maxSubArraySum = -999999;

        // for every ~  i..i-k
        // sum k values, and compare
        for (int i = 0; i < array.size() - k + 1; ++i)
        {
            int WindowSum = 0;
            for (int j = 0; j < k; ++j)
            {
                WindowSum += array[i + j];
            }

            maxSubArraySum = std::max(WindowSum, maxSubArraySum);
        }

        return maxSubArraySum;
    }

    int maxSubArray_slidingWindow(int k)
    {
        if (k == 0 || k > array.size())
            return -1;

        int windowSum = 0;
        // calculate first window, before starting to slide
        for (int i = 0; i < k; ++i)
            windowSum += array[i];

        int maxSubArraySum = -999999;

        // sliding here
        for (int i = k; i < array.size(); ++i)
        {
            // adding one current value,
            windowSum += array[i];
            //  removing 'k' location back value
            windowSum -= array[i - k];
            maxSubArraySum = std::max(maxSubArraySum, windowSum);
        }
        return maxSubArraySum;
    }
};

int main()
{
    method obj;
    obj.push_back(-1);
    obj.push_back(3);
    obj.push_back(0);
    obj.push_back(3);
    obj.push_back(2);

    obj.printArray();

    // std::cout << obj.maxSubArray_bruteForce(0) << std::endl;
    // std::cout << obj.maxSubArray_bruteForce(1) << std::endl;
    std::cout << obj.maxSubArray_bruteForce(2) << std::endl;
    // std::cout << obj.maxSubArray_bruteForce(3) << std::endl;
    // std::cout << obj.maxSubArray_bruteForce(4) << std::endl;
    // std::cout << obj.maxSubArray_bruteForce(5) << std::endl;

    std::cout << obj.maxSubArray_slidingWindow(2) << std::endl;
    // std::cout << obj.maxSubArray_slidingWindow(4) << std::endl;

    return 0;
}