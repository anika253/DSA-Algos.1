class Solution {
public:
vector<int>helper(string &y)
{
    vector<int>one;
    string x;
    for(int i = 0 ; i<y.size(); i++)
        {
            if(y[i]!='.'){
            x+=y[i];}
            if(y[i]=='.')
            {
                int p=stoi(x);
                one.push_back(p);
                x="";
            }
        }
        one.push_back(stoi(x));
return one;

}
    int compareVersion(string version1, string version2) {
        vector<int>a= helper(version1);
        vector<int>b= helper(version2);
        int n = max(a.size(), b.size());
        for(int i = 0; i < n; i++) {
            int v1 = (i < a.size()) ? a[i] : 0;
            int v2 = (i < b.size()) ? b[i] : 0;

            if(v1 < v2) return -1;
            if(v1 > v2) return 1;
        }
        return 0;
    }
};

  