class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int i =0 ; i<n ; i++)
        {
            sum+= nums[i];

        }
        if(sum%2!=0) return false;

        int target = sum/2;
        vector<vector<int>>dp(n, vector<int>(target+1, 0));
        for( int i = 0 ; i<n ; i++)
        {
            dp[i][0]= 1;
        }
        for( int i = 0 ; i<= target ; i++)
   {     if(nums[0]<= target)
   {
                dp[0][nums[0]]=1;
   }
   }
   for( int i =1 ; i<n; i++)
   {
    for( int tar=1 ; tar<= target ; tar++)
    {
     int nt = dp[i-1][tar];
     int t= false;
     if( nums[i]<= tar)
     {
        t= dp[i-1][tar-nums[i]];

     }
     dp[i][tar]= nt||t;
    }
   }
   return dp[n-1][target];

    }
};