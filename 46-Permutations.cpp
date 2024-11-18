class Solution {
    vector<vector<int>> res;
    vector<int>prem;
    vector<bool>visited;
      void bt(vector<int>& nums){
      

        if(prem.size() == nums.size())
          res.push_back(prem);

        for(int i = 0; i < nums.size(); i++){
           if(visited[i])continue;

           visited[i] = true;
           prem.push_back(nums[i]);
           bt(nums);

           visited[i] = false;
           prem.pop_back();
        }
        

      }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        visited = vector<bool>(nums.size(), false);
      bt(nums);

      return res;

    }
};