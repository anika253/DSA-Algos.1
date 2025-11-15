class Solution {
public:
void solve(vector<int>& nums , int ind ,  vector<vector<int>>&final , vector<int>&ans)
      {
        if(ind==nums.size())
        {
            final.push_back(nums);
            return;

        }
        for( int i = ind ; i<nums.size() ; i++)
        {
            swap(nums[i], nums[ind]);
            solve( nums , ind+1, final , ans);
            swap(nums[i], nums[ind]);
        }
      }
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>final;
        vector<int>ans;
        int ind =0;
        solve(nums,ind , final , ans );
        return final;

    }
};