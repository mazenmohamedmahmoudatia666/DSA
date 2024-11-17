class Solution {
    vector<vector<int>>res;
    vector<int>path;
     void backtracking(vector<vector<int>>& DAG , int node){
    path.push_back(node);

    if(node == DAG.size()- 1){
        res.push_back(path);
    }else{
        for(auto& nigbour : DAG[node]){
            backtracking(DAG , nigbour);
        }
    }
    path.pop_back(); 

    }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        res.clear();
        path.clear();
         backtracking(graph, 0); // Start from node 0
        return res;
        
          
    }
};