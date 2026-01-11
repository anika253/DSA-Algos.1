class Solution {
public:
bool solve(string &s, int i , int j ,vector<vector<int>>&dp, int starti , int maxl )
{
    if(i>=j)
   {
    return 1;
   }
   if(dp[i][j]!=-1)
   {
    return dp[i][j];
   }
   if(s[i]==s[j])
   {
    return dp[i][j] = solve(s , i+1, j-1 , dp , starti , maxl);
   }
   return 0;
}
    string longestPalindrome(string s) {
        int n = s.size();
        int starti = 0;
        int maxl = 1;
        vector<vector<int>>dp( n+1, vector<int>(n+1,-1));

        for( int i = 0 ; i< n ; i++)
        {
            for(int j = i ;j<n ; j++)
            {
                if(solve( s, i , j , dp  ,starti , maxl))
                {
                    if(j-i+1 > maxl){
                    maxl= max(maxl , j-i+1);
                    starti = i;
                }
                }
            }
        }
        return s.substr(starti , maxl);

    }
};