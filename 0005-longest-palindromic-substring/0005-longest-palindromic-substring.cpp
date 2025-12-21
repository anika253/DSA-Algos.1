class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<bool>>t(n, vector<bool>(n, 0));
        int maxL = 1;
        int startI = 0;
        for( int i = 0 ; i< n ; i++)
        {
            t[i][i]=1;
        }
     for( int len =2 ; len <=n ; len++)
     {
        for( int i = 0 ; i<n-len+1; i++)
        {
            int j = i+len-1;
            if(s[i]==s[j] && len==2)
            {
                t[i][j]= 1;
                maxL = 2;
                startI = i;
            }
            else if(s[i]==s[j] && t[i+1][j-1])
            {
                t[i][j]= 1;
                if(j-i+1 > maxL)
                {
                    maxL = j-i+1;
                    startI = i;

                }
                
            }
            else{
                t[i][j]= false;

            }

        }

     }
return s.substr(startI , maxL);
    }
};