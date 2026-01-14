class Solution {
public:
bool isPalind(string temp ,vector<vector<int>>&dp , int i , int j)
{
     if( i>= j) return true;
 if(dp[i][j]!=-1)
 {
    return dp[i][j];
 }

if(temp[i]==temp[j])
{
    return dp[i][j] = isPalind(temp ,dp, i+1, j-1);
} 
return dp[i][j]= false;

}

void solve( string s, vector<string>&ans , vector<vector<string>>&final, int ind , 
 vector<vector<int>>&dp )
 {
    int n = s.size();
    if(ind==n)
    {
        final.push_back(ans);
        return ;
    }
    for(int i= ind ; i<n; i++)
    {
        string temp = s.substr(ind , i-ind+1);
        if(isPalind(temp,dp,  ind , i))
        {
           ans.push_back(temp);
            solve(s , ans, final , ind+( i-ind+1), dp);
            ans.pop_back();
        }
    }
 }
    vector<vector<string>> partition(string s) {
        int n = s.size();
        vector<string>ans;
        vector<vector<string>>final;
        int ind = 0;
        vector<vector<int>>dp(n+1, vector<int>(n+1, -1));

        solve(s, ans, final , ind, dp);
        return final;
    }
};