class Solution {
public:
void solve( string &s , int ind,  unordered_set<string>&st, int currC, int &maxC)
{
    if(ind==s.length())
    {
        maxC = max(maxC, currC);
    }
    for( int j = ind; j<s.length() ; j++)
    {
        string sub = s.substr( ind, j-ind+1);
        if(st.find(sub)==st.end())
        {
            st.insert(sub);
            solve(s, j+1, st, currC+1, maxC);
            st.erase(sub);
        }
    }
}
    int maxUniqueSplit(string s) {
        unordered_set<string>st;
        int ind = 0;
        int currC = 0;
        int maxC = 0;
        solve( s, 0, st, currC, maxC);
        return maxC;
    }
};