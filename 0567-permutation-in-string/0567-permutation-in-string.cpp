class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        sort(s1.begin(), s1.end());
        int n = s1.size();
        int m = s2.size();
        if(n>m) return false;
        for( int i = 0 ; i<= m-n ; i++)
        {
           string subs = s2.substr( i , n);
           sort(subs.begin(), subs.end());
           if( subs == s1)
           {
            return true;
           }
        }
        return false;
        
    }
};