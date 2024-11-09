class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        
        // Create DP table
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        // Base cases: dp[i][0] means transforming word1[0..i-1] to an empty string (deletions)
        for (int i = 0; i <= n; i++) {
            dp[i][0] = i;  // i deletions required to convert word1[0..i-1] to empty
        }
        
        // Base cases: dp[0][j] means transforming an empty string to word2[0..j-1] (insertions)
        for (int j = 0; j <= m; j++) {
            dp[0][j] = j;  // j insertions required to convert empty to word2[0..j-1]
        }

        // Fill the DP table using the recurrence relation
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    // No operation needed if the characters are the same
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    // Otherwise, consider insert, delete, or substitute
                    dp[i][j] = min({dp[i - 1][j] + 1,    // Deletion
                                     dp[i][j - 1] + 1,    // Insertion
                                     dp[i - 1][j - 1] + 1 // Substitution
                    });
                }
            }
        }

        // The bottom-right corner of the DP table will contain the minimum edit distance
        return dp[n][m];
    }
};
