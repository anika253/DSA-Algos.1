class Solution {
public:
const int mod = 1e9+7;
int  dfs( int ind, int mask ,vector<int>& nums, vector<vector<int>>&dp   )
{
    int n = nums.size();
    if( mask == (1<<n)-1)
    {
        return 1;
    }
    if(dp[ind][mask]!=-1)
    {
        return dp[ind][mask];
    }
    long long ans = 0;
    for(int j =0 ; j<n ; j++)
    {
      if((mask &(1<<j))==0)
      {
        if(nums[j]%nums[ind]==0 || nums[ind]%nums[j]==0)
        {
          ans = (ans+ dfs( j , mask|(1<<j), nums,dp))%mod;
        }
      }
    }
  return dp[ind][mask]= ans;
}
    int specialPerm(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp( n , vector<int>( 1<<n , -1));
        long long ans =0;
        for( int i = 0 ; i<n; i++)
        {
            ans+= dfs( i, 1<<i , nums, dp);
        }
      return (int)(ans % mod);


    }
};