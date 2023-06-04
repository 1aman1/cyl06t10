class Solution
{
public:
    struct Plant
    {
        int plantType;
        int growTime;

        Plant(int plantType, int growTime) : plantType(plantType), growTime(growTime) {}
    };

    int earliestFullBloom(vector<int> &plantTime, vector<int> &growTime)
    {
        vector<Plant> saplings;
        int result, time;

        for (int i = 0; i < plantTime.size(); ++i)
            saplings.push_back({plantTime[i], growTime[i]});

        sort(begin(saplings), end(saplings), [](const auto &a, const auto &b)
             { return a.growTime > b.growTime; });

        result = time = 0;
        for (const auto &[p, g] : saplings)
            time += p, result = max(time + g, result);

        return result;
    }
};