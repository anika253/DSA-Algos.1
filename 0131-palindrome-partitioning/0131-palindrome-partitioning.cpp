class Solution {
public:
int n;
bool isPalindrome(string temp)
{  if(temp.empty())return false;

    int i = 0;
    int j = temp.size()-1;
    while(i<=j)
    {
        if(temp[i]!=temp[j])return false;
        i++;
        j--;
    }
    return true;
}
void solve( string s, vector<vector<string>>&final, vector<string>&ans, string temp, int ind  )
{
    if(ind==n)
    {
        final.push_back(ans);
        return;
    }
    for( int i = ind ; i<n ; i++)
    {
        temp = s.substr( ind ,i-ind+1);
        if(isPalindrome(temp))
        {
            ans.push_back(temp);
            solve(s, final , ans, temp, ind+(i-ind+1));
            ans.pop_back();
        }

    


    }


}    vector<vector<string>> partition(string s) {
       n= s.size();
        vector<vector<string>>final;
        vector<string>ans;
        string temp ="";
        int ind=0;
        solve( s, final , ans, temp , ind);
        return final;
    }
};