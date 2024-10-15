class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses, 0);  // Indegree array for all courses
        vector<vector<int>> graph(numCourses);  // Adjacency list to store course dependencies

        // Build the graph and calculate indegree
        for (auto& prereq : prerequisites) {
            int course = prereq[0];
            int prerequisite = prereq[1];
            graph[prerequisite].push_back(course);  // prerequisite -> course
            indegree[course]++;  // Increment indegree of the course
        }

        // Initialize the queue with all courses that have no prerequisites (indegree == 0)
        queue<int> ready;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0)
                ready.push(i);
        }

        vector<int> ordering;  // To store the topological order of courses
        while (!ready.empty()) {
            int course = ready.front();
            ready.pop();
            ordering.push_back(course);

            // Process all neighbors (courses dependent on the current course)
            for (int neighbor : graph[course]) {
                if (--indegree[neighbor] == 0)
                    ready.push(neighbor);
            }
        }

        // If we were able to order all courses, there was no cycle
        return ordering.size() == numCourses;
    }
};
