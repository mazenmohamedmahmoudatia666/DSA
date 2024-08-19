#include <iostream>
#include <vector>
#include <cstring>
#include <climits>
#include <algorithm>
#include <cassert>
using namespace std;

/*

Direct loop problem

Let perfectSquares(n) is our DP function

What are the possible choices?
Just loop on all perfect squares. We can simply generate them by a loop i => i * i
	How many choices per value n? sqrt(n)

So time complexity is O(n sqrt(n) )
 */

const int MAX = 10000 + 1;
int dp[MAX];

//vector<int> cost;

int perfectSquares(int n) {
	if (n <= 0)
		return 0;

	auto &ret = dp[n];
	if (ret != -1)
		return ret;

	ret = INT_MAX;
	for (int i = 1;i * i <= n; ++i) 	// a smart condition is i * i <= n
		ret = min(ret, 1 + perfectSquares(n - i * i));
	
	return ret;
}

class Solution {
public:
	int numSquares(int n) {
		memset(dp, -1, sizeof(dp));
		return perfectSquares(n);
	}
};



