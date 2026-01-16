class Solution {
public:
unordered_set<int>helper( int x , vector<int>&fence)
{
    fence.push_back(1);
    fence.push_back(x);
    unordered_set<int>st;
    sort(fence.begin(), fence.end());
    for( int i = 0 ; i< fence.size(); i++)
    {
        for(int j = i+1 ; j<fence.size(); j++)
        {
            int diff = fence[j]-fence[i];
            st.insert(diff);
        }
    }
    return st;

}
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        int mod = 1e9+7;
        auto hedge =helper( m , hFences);
        auto vedge = helper( n ,vFences);
        int res = 0;
        for( auto &e: hedge)
        {
            if(vedge.find(e)!= vedge.end())
            {
              res = max(res, e);

            }
        }
        if(res==0)
        { res = -1;}
        else{
            res= 1LL* res*res % mod;
        }
return res;
    }
};