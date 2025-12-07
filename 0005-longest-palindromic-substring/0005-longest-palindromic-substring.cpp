class Solution {
public:

bool isPalindrome(int i , int j , string &s, vector<vector<int>>&dp)
{
  if(i>=j)return true;
  if(dp[i][j]!=-1)return dp[i][j];
  if(s[i]==s[j])
  {
    return isPalindrome(i+1, j-1 , s, dp);
  }

return dp[i][j]=false;


}
    string longestPalindrome(string s) {
        int n= s.size();
        int len = INT_MIN;
        int startI = -1;
        vector<vector<int>>dp(n , vector<int>( n , -1));
        for(int i = 0 ; i<n ; i++)
        {
            for(int j = i ; j<n ; j++)
            {
                if(isPalindrome(i, j , s, dp))
                {
                    if(len <  j-i+1)
                    {
                        len = j-i+1;
                        startI = i;
                    }
                }
            }
        }
        if(startI ==-1) return "";
        return s.substr( startI , len);
    }
};