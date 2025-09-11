class Solution {
public:
    string sortVowels(string s) {
        int n = s.size();
        vector<char>a;
        for(int i = 0 ; i<n ; i++)
        {
            if(s[i]=='A' || s[i]=='E'|| s[i]=='I'|| s[i]=='O' ||s[i]=='U' || s[i]=='a'|| s[i]=='e'|| s[i]=='i'|| s[i]=='o' || s[i]=='u')
            {
              a.push_back(s[i]);
            }

        }
        sort(a.begin(), a.end() );
        int j = 0;
        for(int i = 0 ; i<n ; i++)
        {
            if(s[i]=='A' || s[i]=='E'|| s[i]=='I'|| s[i]=='O' ||s[i]=='U' || s[i]=='a'|| s[i]=='e'|| s[i]=='i'|| s[i]=='o' || s[i]=='u')
            {
              s[i]= a[j];
              j++;
            }

        }
        return s;
        
    }
};