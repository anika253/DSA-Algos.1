class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int>dp(amount+1, 1e9);
        dp[0]= 0;
        int n = coins.size();
        
        for( int i=1 ; i<=amount; i++)
        {
            for( int j = 0 ; j<n ; j++)
            {
                if(i-coins[j]>=0)
                {
                    dp[i]= min(dp[i], dp[i-coins[j]]+1);
                }
            }
        }
        if(dp[amount]==1e9) return -1;
        return dp[amount];

    }
};