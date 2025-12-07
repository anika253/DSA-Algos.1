class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n= coins.size();
        vector<vector<int>>dp( n , vector<int>(amount+1, 1e9));
            for(int i =  0;i<=amount ; i++)
            {
                if(i%coins[0]==0)
                {
                    dp[0][i]= i/coins[0];
                }
            }
            for(int i = 0; i<n ; i++)
          {
            dp[i][0]=0;
          }
           for(int ind=1 ; ind<n ; ind++)
        {
            for(int tar= 1; tar<=amount; tar++)
            {
                int nt = dp[ind-1][tar];
                int t = 1e9; ;
                if(coins[ind]<=tar)
                {
                    t = 1+dp[ind][tar-coins[ind]];
                }
                dp[ind][tar]= min(t, nt);
            }
        }
        if( dp[n-1][amount]==1e9)return -1;
      else  return dp[n-1][amount];


    }
};