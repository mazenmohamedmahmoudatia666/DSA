class Solution {
  
    
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int n = books.size();
        vector<int> dp(n + 1 , INT_MAX);

        dp[0] = 0;
   
         for(int i = 1; i <= n; i++){
            int total_width = 0 , max_height = 0;
            for(int j = i- 1; j >= 0; j--){
            total_width += books[j][0];
            if(total_width > shelfWidth) break;
            max_height = max(max_height , books[j][1]);
            
           dp[i] = min(dp[i] , dp[j] + max_height);            
         }
         }

        return dp[n];
    }
};
