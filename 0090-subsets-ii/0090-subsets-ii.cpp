class Solution {
public:
void helper(vector<int>& nums,vector<vector<int>>&final,vector<int>&ans, int ind  )
{
    final.push_back(ans);
    for(int i = ind; i<nums.size(); i++)
    {
        if(i!= ind && nums[i]==nums[i-1]) continue;
        ans.push_back(nums[i]);
        helper( nums, final, ans , i+1);
        ans.pop_back();
    
    }
}
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>>final;
        vector<int>ans;
        int ind = 0;
        helper(nums, final , ans, ind);
        return final;
    }
};