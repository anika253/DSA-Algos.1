class Solution {
public:
bool solve(string s, vector<string>& wordDict, vector<int>&dp, unordered_set<string>&st, int ind  )
{ int n = s.size();
  if(ind==n)
  {
    return true;
  }
  if(dp[ind]!= -1)
  {
    return dp[ind];
  }
  
  for( int len = 1; len <= n-ind ; len++)
  {
    string temp = s.substr( ind , len);
    if(st.find(temp)!=st.end() && solve( s, wordDict, dp , st , ind+len))
    {
        return dp[ind]= true;
    }
  }
  return dp[ind]= false;



}
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<int>dp( n, -1);
        int ind = 0;
        unordered_set<string>st;
        for( auto it: wordDict)
        {
            st.insert(it);

        }
        bool t = solve( s, wordDict , dp , st, ind);
        if(t)return true;
        return false;
    }
};