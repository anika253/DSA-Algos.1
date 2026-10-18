class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        unordered_map<char , int>mpp;
        int len = 0;
        int l = 0;
        int r = 0;
        while(r<n)
        {
             mpp[s[r]]++;
           while(mpp[s[r]]>1)
           {
            mpp[s[l]]--;
            l++;
           }
          
           len = max(len, r-l+1);
           r++;

        }
        return len;
    }
};