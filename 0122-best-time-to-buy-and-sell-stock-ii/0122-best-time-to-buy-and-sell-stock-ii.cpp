class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n= prices.size();
        vector<vector<int>>dp(n+1, vector<int>(2, 0));
        int profit = INT_MIN;
        for(int i = n-1 ; i>=0 ; i--)
        {  
            for(int buy = 0 ; buy <=1 ; buy++)
            {
                
                if(buy ==0)
                {
          profit = max(dp[i+1][0], -prices[i]+dp[i+1][1]);
                }
                if(buy ==1)
                {
                    profit = max( dp[i+1][1], prices[i]+dp[i+1][0]);

                }
                dp[i][buy]=profit;
            }
        }
        return dp[0][0];
    }
};