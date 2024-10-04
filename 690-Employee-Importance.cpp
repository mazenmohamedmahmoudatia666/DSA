// Definition for Employee.
/*
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    unordered_map<int, Employee*> mp;

    // Corrected DFS function to calculate the total importance
    int dfs(int id) {
        Employee* emp = mp[id];
        int result = emp->importance;

        for (auto& sub : emp->subordinates) {
            result += dfs(sub);
        }

        return result;
    }

    int getImportance(vector<Employee*> employees, int id) {
        // Fill the map with employee ID to Employee object mapping
        for (auto& emp : employees) {
            mp[emp->id] = emp;
        }

        // Start the DFS to calculate the total importance
        return dfs(id);
    }
};
