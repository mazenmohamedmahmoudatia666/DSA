class Solution {
private:
    string s, m;
    int dp[501][501];

    int process(int i, int j) {
        if (i == s.size()) return m.size() - j; // Insert remaining characters of m
        if (j == m.size()) return s.size() - i; // Delete remaining characters of s

        auto &ret = dp[i][j];
        if (ret != -1) return ret;

        int insert = 0, remove = 0, match = 0;
        if (s[i] == m[j]) {
            match = process(i + 1, j + 1); // Characters match, no edit needed
        } else {
            match = 1 + process(i + 1, j + 1); // Substitute
        }

        remove = 1 + process(i + 1, j); // Delete s[i]
        insert = 1 + process(i, j + 1); // Insert m[j] into s

        ret = min({match, remove, insert});

        return ret;
    }

public:
    int minDistance(string word1, string word2) {
        s = word1;
        m = word2;
        memset(dp, -1, sizeof(dp));

        return process(0, 0);
    }
};
