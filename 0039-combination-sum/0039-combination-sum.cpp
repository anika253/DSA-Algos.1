class Solution {
public:
void solve(     vector<int>&ans,vector<vector<int>>&final, int target , vector<int>& candidates , int ind )
{ int n = candidates.size();
    if(ind==n)
    {
        if(target ==0)
        {
            final.push_back(ans);
        }
        return ;
    }
    if( candidates[ind]<= target)
    {
        ans.push_back(candidates[ind]);
        solve( ans , final , target-candidates[ind], candidates , ind);
        ans.pop_back();

    }
  solve( ans , final , target, candidates , ind+1);
}
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>ans;
        vector<vector<int>>final;
        int ind = 0;
        solve(ans ,final, target, candidates , ind);
        return final;

    }
};