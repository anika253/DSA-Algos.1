class Solution {
public:
void solve(vector<int>& candidates, int target, vector<int>&ds, vector<vector<int>>&final, int ind)
{    int n = candidates.size();
    if(ind==n)
    {
        if(target==0)
        {
            final.push_back(ds);

        }
        return;
    }
   
   if(candidates[ind]<=target)
   {
    ds.push_back(candidates[ind]);
    solve(candidates , target-candidates[ind] , ds, final , ind);
    ds.pop_back();
   }


  solve(candidates , target , ds, final , ind+1);

}
vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        vector<int>ds;
        vector<vector<int>>final;
        int ind = 0;
        solve(candidates, target, ds, final , ind);
        return final;


    }
};