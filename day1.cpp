#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <numeric>
#include <algorithm>

int main()
{
    std::cout << "Hello World\n";

    std::string line;
    std::ifstream myfile ("C:\\Users\\SounakBhattacharya\\Desktop\\day1.txt");

    struct Food {
        std::vector<int> calories;
        int s;  // sum
    };

    std::vector<Food> all_food;
    std::vector<int> c;

    while (getline(myfile, line))
    {
        if (line == "") {
            Food f;
            f.calories = c;
            f.s = std::accumulate(c.begin(), c.end(), 0);
            all_food.push_back(f);
            c.clear();
        }
        else {
            c.push_back(stoi(line));
        }
    }

    auto it = std::max_element(all_food.begin(), all_food.end(),
                               [](Food a, Food b) { return a.s < b.s; });
    auto max = *it;
    std::cout << max.s << std::endl;


    std::sort(all_food.begin(), all_food.end(), [](Food a, const Food b)
        {
            return a.s > b.s;
        });
    std::cout << all_food[0].s + all_food[1].s + all_food[2].s << std::endl;

    return 0;
}
