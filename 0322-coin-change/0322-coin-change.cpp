class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        int sum = amount+1;
        vector<vector<int>> dp(n+1,vector<int>(amount+1,INT_MAX));
        for(int i=0;i<=n;i++){
            dp[i][0]=0;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<sum;j++){
                int x = j-coins[i-1];
                int y = dp[i-1][j];
                dp[i][j]=y;
                if(x<0){
                    continue;
                }
                int x1 = dp[i][x];
                
                int z = dp[i-1][j-coins[i-1]];
                if(x1!=INT_MAX){
                    x1++;
                }
                if(z!=INT_MAX){
                    z++;
                }
                dp[i][j]=min({x1,y,z});
            }
        }
        if(dp[n][sum-1]==INT_MAX){
            return -1;
        }
        return dp[n][sum-1];
    }
};