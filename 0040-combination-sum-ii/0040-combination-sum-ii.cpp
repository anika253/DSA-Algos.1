class Solution {
public:
void solve( vector<int>&ans ,vector<vector<int>>&final, int ind ,vector<int>&c, int target )
{ int n = c.size();
    if(target ==0)
    {
        final.push_back(ans);
        return ;
    }
    for( int i = ind ; i<n ; i++)
    {
        if(target < c[i]) break;
        if(i!= ind && c[i]==c[i-1]) continue;
        ans.push_back(c[i]);
        solve( ans , final ,i+1, c,target-c[i]);
        ans.pop_back();
    }
}
    vector<vector<int>> combinationSum2(vector<int>&c, int target) {
        vector<int>ans;
        sort(c.begin(), c.end());
        vector<vector<int>>final;
        int ind = 0;
        solve( ans , final , ind , c, target);
        return final;

    }
};