class Solution {
public:
    int compress(vector<char>& chars) {
        int i = 0;
        int ind = 0;
        int n = chars.size();
        while(i<n)
        {
            char ch = chars[i];
            int cnt = 0;
            while(i<n && chars[i]==ch)
            {
                cnt++;
                i++;
            }
            chars[ind]=ch;
               ind++;
            if(cnt>1)
            {
              string str  = to_string(cnt);
              for( auto it:str)
              {
                chars[ind]= it;
                ind++;
              }
            






                   }     
                     }
                     return ind;
    }
};