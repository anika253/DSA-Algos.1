class Solution {
public:
void helper(vector<int>& c, int target, vector<vector<int>>&final, vector<int>&ans, int ind)
{
    if(target==0)
    {
        final.push_back(ans);
        return;
    }
    for(int i = ind; i<c.size(); i++)
    {
        if( target< c[ind]) break;
         if( i!= ind && c[i]==c[i-1]) continue;
         ans.push_back( c[i]);
         helper( c, target-c[i], final , ans  ,i+1);
         ans.pop_back();
    }

}
 vector<vector<int>> combinationSum2(vector<int>& c, int target) {
        int n= c.size();
        sort( c.begin(), c.end());
        vector<vector<int>>final;
        vector<int>ans;
        int ind = 0;
      helper( c, target, final , ans , ind);
      return final;

    }
};