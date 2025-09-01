class Solution {
public:
void helper(vector<int>& candidates, int target,  vector<vector<int>>&final,  vector<int>&ans, int ind)
{ int n = candidates.size();
    if(ind==n)
    {
        if(target==0)
        {
            final.push_back(ans);
            
        }
        return;
    }
   
    
        if(target >= candidates[ind])
        {
            ans.push_back( candidates[ind]);
            helper(candidates, target-candidates[ind], final , ans, ind);// stay at same index;
            ans.pop_back();
        }
        helper(candidates, target, final , ans, ind+1);
    }












    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        vector<vector<int>>final;
        vector<int>ans;
        int ind=0;
      helper( candidates,target , final , ans , ind);
        return final;
    }
};