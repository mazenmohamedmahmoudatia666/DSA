#include<iostream>
#include<vector>
#include<queue>
#include<set>
#include<unordered_set>
#include<unordered_map>
using namespace std;




/*
 Once you think in this problem as a graph where the state is pair: current water in each juge
 Then from pair (jug1, jug2) we can try the 6 available substates (e.g. empty the first)
 Then normal BFS to find the solution
 \t Why BFS? As the search space is huge. We need to find the answer as soon as possible

 However, most of the BFS code will TLE. I don't care about that here as my goal to write this BFS states code

 Out of scope improvements:
 - This problem has O(1) math solution based on coprimes/gcd: https://leetcode.com/problems/water-and-jug-problem/discuss/83714/A-little-explanation-on-GCD-method.-C%2B%2BJavaPython
 - https://leetcode.com/problems/water-and-jug-problem/discuss/1476878/C%2B%2B-BFS-Solution

 Deciding the total number of states is out of our scope for this very irregular problem
 \t Just notice: it is not just the total number of states
 \t as we only visit a susbet

 */

class Solution {
\tbool found = false;

\ttypedef unordered_map<int, unordered_set<int>> HASHSET;
\tvoid process(queue<vector<int>> &q, HASHSET &visited, int jug1, int jug2, int target) {
\t\tif (jug1 + jug2 == target) {
\t\t\tfound = true;
\t\t\treturn;
\t\t}
\t\tif (jug1 > jug2)  \t\t// optimization: let's make the state canonical
\t\t\tswap(jug1, jug2);

\t\tif (!visited[jug1].count(jug2)) {
\t\t\tvisited[jug1].insert(jug2);
\t\t\tq.push( { jug1, jug2 });
\t\t}
\t}

public:
\tbool canMeasureWater(int CAP1, int CAP2, int target) {
\t\tif (CAP1 + CAP2 == target)
\t\t\treturn 1;

\t\tif (CAP1 + CAP2 < target)
\t\t\treturn 0;

\t\tqueue<vector<int>> q;
\t\tHASHSET visited;
\t\tfound = false;
\t\tprocess(q, visited, 0, 0, target);

\t\twhile (!found && !q.empty()) {
\t\t\tint jug1 = q.front()[0], jug2 = q.front()[1];
\t\t\tq.pop();

\t\t\tint m1 = min(jug1, CAP2 - jug2), m2 = min(jug2, CAP1 - jug1);
\t\t\tprocess(q, visited, 0, jug2, target);\t// empty 1
\t\t\tprocess(q, visited, jug1, 0, target);\t// empty 2
\t\t\tprocess(q, visited, CAP1, jug2, target);\t// fill 1
\t\t\tprocess(q, visited, jug1, CAP2, target);\t// fill 2
\t\t\tprocess(q, visited, jug1 - m1, jug2 + m1, target);\t// pour from 1
\t\t\tprocess(q, visited, jug1 + m2, jug2 - m2, target);\t// pour from 2
\t\t}
\t\treturn found;
\t}
};