class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        unordered_map<char, int>mpp;
        int l = 0;
        int r = 0;
        int maxl = 0;
        int maxf = 0;

        while(r<n)
        {
            mpp[s[r]]++;
            maxf= max(maxf, mpp[s[r]]);
            while(r-l+1 - maxf >k)
            {
                mpp[s[l]]--;
                maxf = 0;
                for( auto it: mpp)
                {
                    maxf = max(maxf, it.second);
                }
                l++;
            }
            if(r-l+1- maxf <=k)
            {
                maxl = max(maxl, r-l+1);
            }
            r++;


        }
        return maxl;
    }
};