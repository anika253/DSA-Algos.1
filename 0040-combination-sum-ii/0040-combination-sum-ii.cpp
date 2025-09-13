class Solution {
public:
void solve(vector<int>&c , int target , vector<vector<int>>&final , vector<int>&ans, int ind, int n)
{
    if( target==0)
    {
        final.push_back(ans);
        return;
    }
    for( int i = ind ; i <n ;i++)
    {
         if(c[i]>target)break;
         if(i!= ind && c[i]==c[i-1])continue;
         ans.push_back(c[i]);
         solve( c, target-c[i], final , ans, i+1, n);
         ans.pop_back();
    }
}
    vector<vector<int>> combinationSum2(vector<int>& c, int target) {
        int n = c.size();
        sort( c.begin(),c.end());
        vector<vector<int>>final;
        vector<int>ans;
        int ind = 0;
        solve(c , target, final  , ans, ind, n);
        return final;

    }
};