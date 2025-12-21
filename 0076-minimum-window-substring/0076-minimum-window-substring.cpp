class Solution {
public:
    string minWindow(string s, string t) {
        int n= s.size();
        int m= t.size();
        if(m >n)return "";
        unordered_map<char , int>hash;
        for( auto it:t)
        {
            hash[it]++;
        }
        int len = INT_MAX;
        int l =0;
        int r = 0;
        int cnt = 0;
        int startI = -1;
        while(r<n)
        {
            if(hash[s[r]]>0)
            {
                cnt++;
            }
            hash[s[r]]--;
      while(cnt==m)
      {
             if(r-l+1<len)
             {
                len = r-l+1;
                startI = l;
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
        if(startI ==-1)return "";
        return s.substr(startI , len);

    }
};