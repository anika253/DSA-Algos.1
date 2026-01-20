class Solution {
public:
void solve(vector<int>& nums, vector<vector<int>>&final , vector<int>&ans, int ind, int n )
{
  if(ind==n)
  { 
    final.push_back(ans);
    return ;
  }
    
  ans.push_back(nums[ind]);
  solve(nums, final , ans, ind+1, n);
  ans.pop_back();
  solve(nums, final , ans, ind+1, n);
}
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>final;
        vector<int>ans;
        int ind = 0;
        solve( nums , final , ans, ind, n );
        return final;

    }
};