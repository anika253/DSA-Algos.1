class Solution {
public:
int n;
void solve(string &digits,  vector<string>&ans, string &temp,unordered_map<char , string>&mpp, int ind)
{
    if(ind==n)
    {
        ans.push_back(temp);
        return;
    }

    char ch = digits[ind];
    string ds = mpp[ch];
    for( int i =0; i<ds.size(); i++)
    {
       temp.push_back(ds[i]);
       solve(digits , ans, temp, mpp, ind+1);
       temp.pop_back();

    }

}
    vector<string> letterCombinations(string digits) {
        
        vector<string>ans;
         if(digits.size()==0)
        {
            return ans;
        }
        string temp = "";
       n= digits.size();
        int ind = 0;
        unordered_map<char , string>mpp;
        mpp['2']="abc";
        mpp['3']="def";
        mpp['4']="ghi";
        mpp['5']="jkl";
        mpp['6']= "mno";
        mpp['7']= "pqrs";
        mpp['8']= "tuv";
        mpp['9']="wxyz";
        solve(digits, ans, temp, mpp, ind);
        return ans;
    }
};