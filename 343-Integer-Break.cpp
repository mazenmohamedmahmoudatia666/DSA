#include <iostream>
#include <vector>
#include <cstring>
#include <climits>
#include <climits>
using namespace std;

const int MAX = 58 + 1;
int dp[MAX];

class Solution {
public:
\tint productSum(int n) {
\t\tif (n == 1)
\t\t\treturn 1;

\t\tauto &ret = dp[n];
\t\tif (ret != -1)
\t\t\treturn ret;

\t\tret = n;\t// default don't divide
\t\tfor (int i = 1; i < n; i++)
\t\t\tret = max(ret, i * productSum(n - i));

\t\treturn ret;
\t}

\tint integerBreak(int n) {
\t\t// Special case for these 2 numbers: must k >= 2
\t\tif (n == 2 || n == 3)
\t\t\treturn n-1;

\t\tmemset(dp, -1, sizeof(dp));
\t\treturn productSum(n);
\t}
};

