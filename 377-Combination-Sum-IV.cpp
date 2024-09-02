#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int MAX_T = 5000 + 1;
int memory[MAX_T];
vector<int> numList;  // Renamed from 'numbers' to 'numList'

int combinationSum(int target) {
    if (target < 0)
        return 0;

    if (target == 0)
        return 1;  // One valid permutation

    auto &ret = memory[target];
    if (ret != -1)
        return ret;

    ret = 0;
    for (auto &value : numList) {  // Updated to 'numList'
        if (target >= value) {
            ret += combinationSum(target - value);
        }
    }
    return ret;
}

class Solution {
public:
    int combinationSum4(vector<int> &nums, int target) {
        numList = nums;  // Updated to 'numList'
        memset(memory, -1, sizeof(memory));
        return combinationSum(target);
    }
};
