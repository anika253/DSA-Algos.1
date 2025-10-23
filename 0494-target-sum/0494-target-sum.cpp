class Solution {
public:
int S;
int solve(vector<int>& nums, int target,   vector<vector<int>>&dp, int ind, int sum)
{
    if( ind==nums.size())
    {
        if( sum == target ) return 1;
         else if(sum!= target) return 0;
    }
    if(dp[ind][sum+S]!=-1)
    {
        return dp[ind][sum+S];
    }
    int l = solve( nums,target , dp , ind+1, sum+nums[ind]);
    int r = solve( nums, target , dp , ind+1, sum-nums[ind]);
    return dp[ind][sum+S]=l+r;
}
    int findTargetSumWays(vector<int>& nums, int target) {
    S = accumulate(begin(nums), end(nums), 0);
    int n = nums.size();
        vector<vector<int>>dp( n, vector<int>(2*S+1, -1));
        return solve( nums , target , dp , 0 , 0);

    }
};