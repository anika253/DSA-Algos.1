class Solution {
public:
const int MOD = 1e9+7;
    int numSub(string s) {
        int n = s.size();
        int total = 0;
        int cnt = 0;
        for(auto it:s)
        {
            if( it=='1')
            {
                cnt++;
            }
            if(it=='0')
            {
                cnt=0;
            }
            total= (total+cnt)%MOD;

        }
        return total;
    }
};