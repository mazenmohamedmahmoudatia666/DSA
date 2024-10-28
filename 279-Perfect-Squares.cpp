class Solution {
    int dp[10001];
     int perfet(int m){
        int perfect_square = sqrt(m);
        if (m == 0) {
            return 0;
        }


        auto&ret = dp[m];
        if(ret != -1)
        return ret;

          ret = INT_MAX;
         for(int i = 1; i <= sqrt(m); i++){
            ret = min(ret , 1 + perfet(m - i*i));
         } 

        return ret;
     }
public:
    int numSquares(int n) {
        memset(dp , -1 , sizeof(dp));
        return perfet(n);
    }
};