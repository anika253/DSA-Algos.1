class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n= s.size();
        int l = 0;
        int r = 0;
        int maxLen = 0;
        unordered_map<char , int>mpp;
        while( r<n)
        {
            while(mpp.find(s[r])!= mpp.end())
            {
                mpp[s[l]]--;
                if( mpp[s[l]]==0)
                {
                    mpp.erase(s[l]);
                }
                l++;
                
            }
            mpp[s[r]]++;
            maxLen = max( maxLen , r-l+1);
            r++;


        }
        return maxLen;
    }
};