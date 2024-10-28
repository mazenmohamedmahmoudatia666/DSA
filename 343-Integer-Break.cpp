class Solution {
   int dp[59];
   int process(int f){
       if (f <= 1) return 1;  // Base case

       auto& ret = dp[f];
       if (ret != -1) return ret;

       ret = 0;  // Initialize to store the maximum product
       for (int i = 1; i < f; i++) {  // Iterate up to f-1
           ret = max(ret, max(i * (f - i), i * process(f - i)));
       }
       return ret;
   }

public:
   int integerBreak(int n) {
       memset(dp, -1, sizeof(dp));
       return process(n);
   }
};
