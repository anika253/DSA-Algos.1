class Solution {
public:
int res = INT_MAX;
int n;
void solve( int ind, vector<int>&cookies, vector<int>&children , int k)
{
    if(ind==cookies.size())
    {
        int ans = *max_element(begin(children), end(children));
        res = min(res, ans);
        return;
    }
    int candy = cookies[ind];
    for( int i =0 ; i<k ; i++)
    {
        children[i]+=candy;
        solve(ind+1,cookies, children , k);
        children[i]-=candy;
    }
}
    int distributeCookies(vector<int>& cookies, int k) {
  n = cookies.size();
  vector<int>children(k);
  solve(0 , cookies, children ,k);
  return res;

    }
};