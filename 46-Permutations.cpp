// https://leetcode.com/problems/permutations/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <cstring>
using namespace std;

/*
This is not an easy idea to get.
It can be also challenging to understand and trace; unless
You used my way on tracing recursion: what NOT how

Let permute_bt(idx)
\tis a function that generates all permutations starting from this idx
\tThen final answer is permute_bt(0)

So for input [2, 1, 5, 9]
permute_bt(0) generates all 4! choices

permute_bt(2) is generating all permutations from idx = 2
\twhich are: [2, 1, 5, 9] and [2, 1, 9, 5]

permute_bt(1) is generating all permutations from idx = 1
\twhich are 8 entries

Now based on the definition, how can we code it:

Assume we are at idx = 0:
\t[2, 1, 5, 9]
\tIf we fixed the 2: we can generate 8 permutations from [1, 5, 9]
\tNow, after 2 is done. We know another value can come; so we try all
\tLet's swap 2 with 1 ==> [1, 2, 5, 9]
\tNow generate 8 permutations for [2, 5, 9]
\tLet's swap 2 with 5 ==> [5, 1, 2, 9]
\tNow generate 8 permutations for [1, 2, 9]
\tLet's swap 2 with 9 ==> [9, 1, 5, 2]
\tNow generate 8 permutations for [1, 5, 2]

\tThis is how we generate it. Trace using WHAT not HOW

Complexity: by definition; n!

 */

vector<vector<int>> perm_list;
vector<int> nums;

void permute_bt(int idx) {
\tif (idx == (int)nums.size()) {
\t\tperm_list.push_back(nums);
\t\treturn;
\t}
\t// Starting from idx: try all values to the end of the array
\t// as starting value, then generate permutations for remaining of list
\tfor (int i = idx; i < (int)nums.size(); i++) {
\t\tswap(nums[i], nums[idx]);
\t\tpermute_bt(idx + 1);
\t\tswap(nums[i], nums[idx]);\t// undo
\t}
}

class Solution {
public:
\tvector<vector<int>> permute(vector<int> &nums_) {
\t\tnums = nums_;
\t\tperm_list.clear();
\t\tpermute_bt(0);
\t\treturn perm_list;
\t}
};

