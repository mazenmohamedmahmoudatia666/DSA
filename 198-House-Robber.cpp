class Solution {
    vector<int> dp;
    vector<int>house;

    int theaf(int idx){

        if(idx >= house.size())
        return 0;

        auto&ret = dp[idx];
        if(ret != -1){
            return ret;
        }

       int leave = theaf(idx + 1);
       int take = 0;
       take =  house[idx]  + theaf(idx + 2);
       
       ret = max(leave , take);
       return ret;


    }
public:
    int rob(vector<int>& nums) {
         dp.resize(nums.size() + 1, -1);
         house = nums;
         return theaf(0);
    }
};