class Solution {
    vector<int> dp; // 1D DP array to store minimum height for books from start up to index `i`
    
    int process(int i, vector<vector<int>>& books, int shelfWidth) {
        if (i >= books.size()) return 0; // Base case: no more books to place
        
        auto&ret = dp[i];
        if ( ret!= -1) return ret; // If already computed, return the result
        
        int width = 0, height = 0, minHeight = INT_MAX;

        // Try placing books on the current shelf up to the width limit
        for (int j = i; j < books.size(); j++) {
            width += books[j][0]; // Accumulate book width

            if (width > shelfWidth) break; // Exceeds width, stop adding books

            height = max(height, books[j][1]); // Track the maximum height on the current shelf
            minHeight = min(minHeight, height + process(j + 1, books, shelfWidth)); // Recursive step
        }

        return ret = minHeight; // Store the result in dp array
    }
    
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        dp = vector<int>(books.size(), -1); // Initialize dp array with -1 for memoization
        return process(0, books, shelfWidth); // Start from the first book
    }
};
