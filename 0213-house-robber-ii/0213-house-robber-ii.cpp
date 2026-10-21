class Solution {
public:
int solve(vector<int>&arr, vector<int>&dp)
{ int x = dp.size();
dp[0]= arr[0];
for( int i= 1; i<x; i++)
{
    int p = arr[i];
    if(i>1)
    {
        p+= dp[i-2];
    }
    int np = dp[i-1];
    dp[i]= max(p, np);
}
return dp[x-1];
}
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>num1;
        vector<int>num2;
        if(nums.size()==0) return 0;
        if(nums.size()==1) return nums[0];
        for( int i = 0 ; i<n; i++)
        {
          if(i!=n-1)num1.push_back(nums[i]);
          if(i!=0) num2.push_back(nums[i]);
        }
        vector<int>dp(n-1,-1);
        int a = solve(num1, dp);
        int b = solve(num2, dp);
     int final = max(a, b);
     return final;

    }
};