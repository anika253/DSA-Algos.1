class Solution {
public:
void solve(vector<int>&nums, int ind, int n,  vector<vector<int>>&final, vector<int>&ans )
{
    if(ind==n)
    {
        final.push_back(ans);
        return ;
    }
    ans.push_back(nums[ind]);
    solve(nums, ind+1, n , final , ans);
    ans.pop_back();
     solve(nums, ind+1, n , final , ans);

}
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        int ind = 0;
        vector<vector<int>>final;
        vector<int>ans;
        solve( nums, ind , n, final , ans);
        return final;


    }
};