// CollectJewels.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

class JewelStone
{
public:
    int weight, value;
    JewelStone(int w, int v)
        : weight(w)
        , value(v)
    { }
};

int GetValue(const std::vector<JewelStone*>& j)
{
    int value = 0;
    for (auto& v : j)
        value += v->value;

    return value;
}

void GetMaxValue(std::vector<JewelStone*>& stones, int start, int sum, int& maxValue, std::vector<JewelStone*>& picked)
{
    if (sum == 0)
    {
        maxValue = std::max(maxValue, GetValue(picked));
        return;
    }

    if (sum > 0)
        maxValue = std::max(maxValue, GetValue(picked));

    if (start == static_cast<int>(stones.size()) || sum < 0)
        return;

    for (int i = start; i < static_cast<int>(stones.size()); ++i)
    {
        picked.push_back(stones[start]);
        GetMaxValue(stones, i + 1, sum - stones[start]->weight, maxValue, picked);
        picked.pop_back();
    }
}

int GetMaxValue(std::vector<JewelStone*>& stones, int capacity)
{
    std::vector<JewelStone*> picked;
    int maxValue = 0;

    GetMaxValue(stones, 0, capacity, maxValue, picked);
    return maxValue;
}

void Release(std::vector<JewelStone*>& stones)
{
    for (auto& s : stones)
        delete s;
}

int main()
{
    while (true)
    {
        std::cout << "Number of stone and capacity: ";
        int count = 0, capacity = 0;
        std::cin >> count >> capacity;
        if (count == 0 && capacity == 0)
            break;

        std::vector<JewelStone*> stones(count, nullptr);
        for (int i = 0; i < count; ++i)
        {
            int w = 0, v = 0;
            std::cin >> w >> v;
            stones[i] = new JewelStone(w, v);
        }

        int maxValue = GetMaxValue(stones, capacity);
        std::cout << "The max value is " << maxValue << std::endl;
        Release(stones);
    };
}
