// https://leetcode.com/problems/similar-string-groups/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <limits>
#include <queue>
using namespace std;

/*
 Direct. Consider every string a node.
 2 similar strings as a connected edge
 	 For every pair of strings, check similarity

 	 similarity can be done in O(n)

 O(n^3), but actually better as similarity returns fast

 */

class UnionFind {
private:
	vector<int> rank, parent;
	void link(int x, int y) {
		if (rank[x] > rank[y])
			swap(x, y);	// force x to be smaller

		parent[x] = y;
		if (rank[x] == rank[y])	// equal case
			rank[y]++;
	}
public:
	int forests { 0 };

	UnionFind(int n) {
		rank = vector<int>(n), parent = vector<int>(n);
		forests = n;	// Number of the current forests

		for (int i = 0; i < n; ++i)
			parent[i] = i, rank[i] = 1;
	}

	int find_set(int x) {
		if (x == parent[x])
			return x;
		// This is the path compression
		// the top parent is returned and we re-link
		return parent[x] = find_set(parent[x]);
	}

	bool union_sets(int x, int y) {
		x = find_set(x), y = find_set(y);
		if (x != y) {	// Different components
			link(x, y);
			forests--;	// 2 merged into 1
		}
		return x != y;
	}
};

// compare and see how many different letters
bool isSimilar(string &a, string &b) {
	int diff = 0;
	for (int i = 0; i < (int)a.size(); i++) {
		if (a[i] != b[i])
			diff += 1;

		if (diff > 2)
			return false;
	}
	return true;
}

class Solution {
public:
	int numSimilarGroups(vector<string> &strs) {
		// Just create a graph
		int n = strs.size();
		UnionFind uf(n);

		for (int i = 0; i < n; ++i) {
			for (int j = i + 1; j < n; ++j) {
				if (isSimilar(strs[i], strs[j]))
					uf.union_sets(i, j);
			}
		}
		return uf.forests;
	}
};

