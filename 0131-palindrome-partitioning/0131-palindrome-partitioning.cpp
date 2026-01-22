class Solution {
public:
bool isPalind(string& s,vector<vector<int>>&dp, int i , int j)
{
    if(i>= j) return true;
    if(dp[i][j]!=-1) return dp[i][j];
    if(s[i]==s[j])
    {
        return dp[i][j]= isPalind(s, dp , i+1, j-1);
    }
    return dp[i][j]= false;


}
  void solve( string &s ,vector<string>&temp, vector<vector<string>>&final, int ind , int n , vector<vector<int>>&dp)
  {
    if(ind==n)
    {
        final.push_back(temp);
        return;
    }
    for(int i = ind ;i<n ; i++)
    {
        string x = s.substr(ind , i-ind+1);
        if(isPalind(s, dp ,ind,i))
        {
            temp.push_back(x);
            solve(s,temp , final, ind+(i-ind+1) , n, dp);
            temp.pop_back();
        }
    }
  }
    vector<vector<string>> partition(string s) {
        int n = s.size();
        int ind = 0;
        vector<string>temp;
        vector<vector<int>>dp(n+1, vector<int>(n+1, -1));

        vector<vector<string>>final;
       solve( s, temp , final , ind, n, dp );
       return final;

    }
};