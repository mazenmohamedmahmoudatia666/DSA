// https://leetcode.com/problems/global-and-local-inversions/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <limits>
#include <random>
using namespace std;

/*
Merge sort can be used in general to solve counting inversions

 We can use merge sort to solve this problem
 - count inversions on left subarray
 - count inversions on right subarray
 - in merging, every number in left


[10, 20, 30, 40] vs [1, 15, 70]
	We know 10 vs 1: then 1 is smaller than 10
		But actually 1 < [10, 20, 30, 40] = 4 conversions

	then 10 vs 15: 10 wins. No conversions

	then 15 vs 20: 15 wins
		but actually 15 < [20, 30, 40] = 3 conversions

	Then if 2 numbers are in conflict
		we need md-i+1 overall conversions (remaining of the first array)


Note: This problem asks only for boolean NOT actual counting
	Given this advantage, we can develop O(n) solution as in editorial
 */

vector<int> tmp;	// Create with nums size

long long merge_sorted_subarrays(vector<int> &nums, int start, int md, int end) {
	long long conversions = 0;
	for (int i = start, j = md + 1, k = start; k <= end; k++) {
		if (i > md)					// start is done
			tmp[k] = nums[j++];
		else if (j > end)			// end is done
			tmp[k] = nums[i++];
		else if (nums[i] < nums[j])	// start is smaller
			tmp[k] = nums[i++];
		else {
			tmp[k] = nums[j++];
			conversions += md-i+1;
		}
	}
	for (int i = start; i <= end; i++)
		nums[i] = tmp[i];

	return conversions;
}

long long merge_sort(vector<int> &nums, int start, int end) {
	if (start == end)
		return 0;

	int md = start + (end - start) / 2;
	long long conversions = merge_sort(nums, start, md);
	conversions += merge_sort(nums, md + 1, end);
	conversions += merge_sorted_subarrays(nums, start, md, end);

	return conversions;
}

class Solution {
public:
	bool isIdealPermutation(vector<int> &nums) {
		tmp = nums;

		long long local_conversions = 0;	// compute before updating the array
		for (int i = 0; i < (int) nums.size() - 1; i++)
			local_conversions += nums[i] > nums[i + 1];

		long long global_conversions = merge_sort(nums, 0, (int) nums.size() - 1);

		return local_conversions == global_conversions;
	}
};


