class Solution {
public:
void solve( int ind ,vector<int>& nums , vector<vector<int>>&final )
{
    int n= nums.size();
    if(ind==n)
    {
        final.push_back(nums);
        return;
    }
    for( int i= ind ; i<n ; i++)
    {
        swap(nums[i], nums[ind]);
        solve(ind+1, nums, final);
        swap(nums[i], nums[ind]);
    }
}
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>final;
        int ind = 0;
        solve( ind , nums ,final );
        return final;
    }
};