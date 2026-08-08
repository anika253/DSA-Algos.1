class Solution {
public:
vector<int>lps(string needle)
{
    int pre = 0;
    int suff= 1;
    int n = needle.size();

    vector<int>lps(n, 0);
    while(suff<n)
    {
        if(needle[pre]==needle[suff])
        {
            lps[suff]= pre+1;
            pre++;
            suff++;
        }
        else if( pre==0)
        {
            lps[suff]= 0;
            suff++;
        }
        else{
           pre = lps[pre-1];
        }
        
    }
    return lps;
}
    int strStr(string haystack, string needle) {
        vector<int>help = lps(needle);
        int f = 0  , s = 0;
        while( f<haystack.size() && s <needle.size())
        {
            if(haystack[f]==needle[s])
            {
                f++;
                s++;
            }
            else{
                if(s==0)
                {
                    f++;
                }
                else{
                    s= help[s-1];
                }
            }
          
        }
        if(s==needle.size())return f-s;
        return -1;
        
    }
};