class Solution {
public:
bool isPalindrome( string &x)
{
   if(x.empty()) return true;
   int i = 0;
   int j = x.size()-1;
   while(i<=j)
   {
    if(x[i]!= x[j])
    {
        return false;
    }
    i++;
    j--;
   }
   return true;

    
}
void solve(int n , string s ,vector<vector<string>>&final, vector<string>&ans , int ind)
{
    if(ind==n)
    {
        final.push_back(ans);
        return ;
    }
    for( int i = ind ; i<n ; i++)
    {
        string temp = s.substr(ind , i-ind+1);
        if(isPalindrome(temp))
        {
            ans.push_back(temp);
            solve( n , s, final , ans, ind+(i-ind+1));
           ans.pop_back();

        }
    
    }
}
    vector<vector<string>> partition(string s) {
        int n= s.size();
        vector<vector<string>>final;
        vector<string>ans;
        int ind = 0;
        solve( n , s , final ,ans,  ind);
        return final;
    }
};