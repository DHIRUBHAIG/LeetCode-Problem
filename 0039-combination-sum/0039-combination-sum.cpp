class Solution {
public:
void solve(int index,vector<int>& candidates,int target,set<vector<int>>&res,vector<int>&path){
    // set<vector<int>>st;
    if(target==0) {
        res.insert(path);
        return;
    }
    if(index == candidates.size() || target < 0) {
            return;
        }

    // pick
    path.push_back(candidates[index]);
    solve(index,candidates,target-candidates[index],res,path);

    // not pick
    path.pop_back();
    solve(index+1,candidates,target,res,path);
}
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        set<vector<int>>res;
        vector<int>path;
        int index=0;
       solve(index,candidates,target,res,path);
      return vector<vector<int>>(res.begin(), res.end());

        
    }
};