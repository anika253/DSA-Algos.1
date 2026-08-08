class Solution {
public:
    string longestPrefix(string s) {
        int pre = 0;
        int suff=1;
        int n = s.size();
        vector<int>lps(n, 0);
        while(suff<n)
        {
            if(s[pre]==s[suff])
            {
                lps[suff]= pre+1;
                pre++;
                suff++;

            }
            else if(pre==0){
                   lps[suff]=0;
                   suff++;
            }
            else{
                pre= lps[pre-1];
                

            }
        }
        int cnt = lps[n-1];
        string ans = "";
        for( int i =0 ; i<cnt; i++)
        {
            ans+=s[i];
        }

    return ans;

    }
};