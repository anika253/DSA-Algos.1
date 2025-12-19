class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n= s.size();
        unordered_map<char , int>mpp;
        int l = 0;
        int r = 0;
        int len = 0;

        while(r<n)
        {
            while(mpp.find(s[r])!= mpp.end())
            {
                mpp[s[l]]--;
                if(mpp[s[l]]==0)
                {
                    mpp.erase(s[l]);
                }
                l++;
            }

            len = max( len , r-l+1);
            mpp[s[r]]++;
            r++;



        }
        return len;

    }
};