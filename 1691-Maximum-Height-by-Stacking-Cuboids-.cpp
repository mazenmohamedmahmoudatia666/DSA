#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

class Solution {
public:
    static const int MAX = 100 + 1; // Make MAX a static constant
    vector<vector<int>> cuboidsg;
    int memory[MAX][MAX];

    bool less_eq(int i, int j) {
        return cuboidsg[i][1] <= cuboidsg[j][1] && cuboidsg[i][2] <= cuboidsg[j][2];
    }

    int LIS(int cur, int prev) {
        if (cur == (int)cuboidsg.size()) return 0;

        auto &ret = memory[cur][prev];
        if (ret != -1) return ret;

        int choice1 = LIS(cur + 1, prev); // Option to leave the current cuboid
        int choice2 = 0;

        // Take the current cuboid if it fits on the previous one
        if (prev == (int)cuboidsg.size() || less_eq(prev, cur)) {
            choice2 = cuboidsg[cur][2] + LIS(cur + 1, cur); // Add height of the current cuboid
        }

        return ret = max(choice1, choice2);
    }

    int maxHeight(vector<vector<int>> &cuboids) {
        if (cuboids.empty()) return 0; // Handle edge case

        // Sort each cuboid's dimensions
        for (auto &c : cuboids) sort(c.begin(), c.end());

        // Sort all cuboids based on their dimensions
        sort(cuboids.begin(), cuboids.end());
        cuboidsg = cuboids;

        memset(memory, -1, sizeof(memory)); // Initialize DP array
        return LIS(0, cuboidsg.size());
    }
};
