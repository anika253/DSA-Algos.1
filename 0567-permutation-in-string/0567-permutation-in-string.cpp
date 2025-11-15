class Solution {
public:
void solve( string s1,int ind ,  vector<string>&ans)
{
   int n = s1.size();
   if(ind==n)
   {
    ans.push_back(s1);
    return;
   }
   for(int i = ind ; i<n ; i++)
   {
    swap(s1[i], s1[ind]);
    solve(s1, ind+1, ans);
    swap(s1[i],s1[ind]);

   }
   


}
    bool checkInclusion(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        if( m<n) return false;
        vector<int>final;
        int ind = 0;
        vector<string>ans;
        solve( s1, ind, ans);
        for( int i =0 ; i<ans.size(); i++)
        {
            if( s2.find(ans[i])!= string ::npos)
            {
                return true;
            }
        }
return false;


    }
};