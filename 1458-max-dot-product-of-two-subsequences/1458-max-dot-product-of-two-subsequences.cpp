class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n= nums1.size();
        int m = nums2.size();
        vector<vector<long long>>dp(n+1, vector<long long >(m+1,-1e9));
        for( int i=1; i<=n;i++)
        {
            for(int j=1; j<=m;j++)
            {
                long long pdt= nums1[i-1]*nums2[j-1];
                dp[i][j]= max({pdt, dp[i-1][j-1]+pdt,
                dp[i-1][j], dp[i][j-1]});




            }

        }
        return dp[n][m];
        
    }
};