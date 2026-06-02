class Solution {
public:
bool solve(string &s, vector<vector<int>>&dp, int i , int j , int startI , int maxL)
{
    if(i>=j)
    {
        return 1;
    }
    if(dp[i][j]!=-1) return dp[i][j];
    if(s[i]==s[j])
    {
        return dp[i][j]= solve( s, dp , i+1, j-1 , startI , maxL);
    }
    return 0;
}
    string longestPalindrome(string s) {
        int maxL = 1;
        int startI = 0;
        int n = s.size();
        vector<vector<int>>dp(n+1, vector<int>(n+1, -1));
        for( int i =  0 ; i<n ; i++)
        {
            for( int j = i ; j<n ; j++)
            {
                if(solve(s, dp , i , j , startI , maxL))
                {
                    if(j-i+1>maxL){
                    startI = i;
                    maxL = j-i+1;
                }
                }
            }
        }
        return s.substr(startI , maxL);
    }
};