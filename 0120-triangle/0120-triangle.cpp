class Solution {
public:
int helper(vector<vector<int>>& triangle, int n ,  vector<vector<int>>&dp )
{
    for( int i=0 ; i<n ; i++)
    {
        dp[n-1][i]= triangle[n-1][i];
    }
    for(int i=n-2 ; i>=0 ; i--)
    {
        for( int j = 0 ; j<=i ;j++)
        {
            int up = triangle[i][j];
            if(i+1<n)
            {
                up+= dp[i+1][j];
            }
            else{
                up+=1e9;
            }
            int diag = triangle[i][j];
            if(i+1 <n && j+1<n)
            {
                diag+= dp[i+1][j+1];

            }
            else{
                diag+=1e9;
            }
            dp[i][j]= min(up , diag);
        }
    }
    return dp[0][0];
}
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>>dp(n, vector<int>(n, 0));
        return helper(triangle, n, dp);
    }
};