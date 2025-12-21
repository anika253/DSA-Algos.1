class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        vector<vector<int>>dp( n, vector<int>( n, 0));
        int cnt = 0;
        for( int i = 0 ; i<n ; i++)
        {
            dp[i][i]=1;
            cnt++;

        }
        for( int len = 2; len <=n ;len++)
        {
            for( int i = 0 ; i<n-len+1; i++)
            {
                int j = i+len-1;
                if(s[i]==s[j] && len==2)
                {
                    dp[i][j]=1;
                    cnt++;
                }
                else if(s[i]==s[j] && dp[i+1][j-1])
                {
                    dp[i][j]=1;
                    cnt++;
                }
                else{
                    dp[i][j]= false;
                }
            }
        }
        return cnt;
    }
};