class Solution {
public:
bool help(string s )
{
unordered_map<char , int>mpp;
 for( auto it: s)
 {
    mpp[it]++;
 }
 for(auto it: mpp)
 {
    if(it.second>1)
    {
        return true;
    }
 }
 return false;
}
    bool buddyStrings(string s, string goal) {
        int n= s.size();
        if(s.size()!= goal.size()) return false;
        if(s==goal)
        {
            return help(s);
        }
        vector<int>ans;
        for(int i = 0 ; i<n; i++)
        {
         if(s[i]!= goal[i])
         {
            ans.push_back(i);
         }
        }
        int t = 0;
        if(ans.size()==2){
        swap(s[ans[0]], s[ans[1]]);}
        return s==goal;

    }
};