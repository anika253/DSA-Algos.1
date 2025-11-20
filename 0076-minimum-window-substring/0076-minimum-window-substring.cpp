class Solution {
public:
    string minWindow(string s, string t) {
        int m = s.size();
        int n = t.size();
        vector<int>hash(128, 0);
        for(int i=0 ; i<t.size(); i++)
        {
            hash[t[i]]++;
        }
        int l= 0;
        int r = 0;
        int cnt=0;
        int startI = -1;
        int len = INT_MAX;
        while(r<m)
        {
            if(hash[s[r]]>0)
            {
                cnt++;
            }
            hash[s[r]]--;
           while(cnt==n)
           {
          if(r-l+1 <len){
            startI =l;
            len = max(len, r-l+1);
          }
            hash[s[l]]++;
            if(hash[s[l]]>0)
            {
                cnt--;
            }
            l++;





           }
   r++;

        }
        if(startI== -1) return "";
        return s.substr( startI,len);
    }

};