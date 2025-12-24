class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n= nums.size();
        int sum = 0;
        for(int i =0 ; i<n ; i++)
        {
            sum+= nums[i];
        }
        if(sum%2!=0)
        {
            return false;
        }
        sum/=2;
        vector<vector<int>>dp( n, vector<int>(sum+1, 0));
        for(int i = 0 ; i<n; i++)
        {
            dp[i][0]=1;
                     

        }           
        for(int i = 0 ; i<= sum ; i++)
        {
           if(nums[0]<=sum )
           {
            dp[0][nums[0]]=1;
           }
        }
        for( int i=1 ; i<n; i++)
        {
            for(int j = 1 ; j<= sum ; j++)
            {
                int np = dp[i-1][j];
                int p = false;
                if(nums[i]<= j)
                {
                    p = dp[i-1][j-nums[i]];
                }
                dp[i][j]= np||p;
            }
        }
              return dp[n-1][sum];       
    }
};