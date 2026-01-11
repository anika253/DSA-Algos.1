class Solution {
public:
string reverse(string &s)
{
    int j = s.size()-1;
    int i = 0;
    while(i<j)
    {
        swap(s[i], s[j]);
        i++;
        j--;
    }
    return s;

}
    string removeKdigits(string num, int k) {
        stack<char>st;
        for( int i =0 ; i<num.size(); i++)
        {
            while(!st.empty() && k>0 && (st.top()-'0')> (num[i]-'0'))
            {
                st.pop();
                k--;
            }
            st.push(num[i]);
        }
        while( k>0 && !st.empty())
        {
            st.pop();
            k--;
        }
        if(st.empty()) return "0";
        string res = "";
        while(!st.empty())
        {
            res+= st.top();
            st.pop();
        }
        while(res.size()!=0 && res.back()=='0')
        {
            res.pop_back();
        }
        res= reverse(res);
        if(res.empty()) return "0";
        return res;
    }
};