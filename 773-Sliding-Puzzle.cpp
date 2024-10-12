#include <vector>
#include <queue>
#include <unordered_set>
#include <string>
#include <algorithm> // For std::swap
using namespace std;

class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        string target = "123450";  // Target state in string format
        string start = "";

        // Convert board to a string
        for (const auto& row : board) {
            for (int num : row) {
                start += to_string(num);
            }
        }

        // If the initial state is already the target
        if (start == target) {
            return 0;
        }

        return bfs(start, target);  // Call the BFS function
    }

private:
    int bfs(const string& start, const string& target) {
        // Possible moves (zero index positions)
        vector<vector<int>> neighbors = {{1, 3}, {0, 2, 4}, {1, 5}, {0, 4}, {1, 3, 5}, {2, 4}};
        
        queue<string> q;  // Queue for BFS
        unordered_set<string> visited;  // Set to track visited states
        q.push(start);
        visited.insert(start);
        
        int steps = 0;  // Count of moves

        // BFS Loop
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                string current = q.front();
                q.pop();

                // If we reach the target state
                if (current == target) {
                    return steps;  // Return the number of moves
                }

                // Find the position of zero
                int zeroPos = current.find('0');

                // Explore all possible neighbors
                for (int neighbor : neighbors[zeroPos]) {
                    string next = current;
                    // Swap zero with the neighboring position
                    swap(next[zeroPos], next[neighbor]);

                    // If this state hasn't been visited yet
                    if (visited.find(next) == visited.end()) {
                        visited.insert(next);  // Mark it as visited
                        q.push(next);  // Add to the queue
                    }
                }
            }
            steps++;  // Increment the move count
        }

        return -1;  // If no solution is found
    }
};
