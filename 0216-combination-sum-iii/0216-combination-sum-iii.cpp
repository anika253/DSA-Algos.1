class Solution {
public:
void solve(int k , int targetSum ,  vector<int>&nums, int ind, vector<int>&ds,vector<vector<int>>&final)
{
    if(ds.size()==k && targetSum ==0)
    {
        final.push_back(ds);
        return ;
    }
    //  if (targetSum < 0 || ds.size() > k) return;
    for(int i = ind; i<nums.size() ; i++)
    {
        ds.push_back(nums[i]);
        solve(k, targetSum-nums[i], nums, i+1, ds, final);
        ds.pop_back();
    }
}
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>nums = {1,2,3,4,5,6,7,8,9};
        int ind = 0;
        int targetSum = n;
        vector<int>ds;
        vector<vector<int>>final;
        solve(k , targetSum , nums, ind, ds, final);
        return final;

    }
};