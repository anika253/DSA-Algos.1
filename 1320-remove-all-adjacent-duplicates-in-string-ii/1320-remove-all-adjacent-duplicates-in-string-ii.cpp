class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char,int>>st;
        int n= s.size();
        for( int i = 0; i<n ; i++)
        {
            if(!st.empty()  && st.top().first==s[i])
            {
                st.top().second++;
                if(st.top().second==k)
                {
                    st.pop();
                }
            }
            else{
                st.push({s[i], 1});
            }

        }
        string temp ="";
        while(!st.empty())
        {
           auto topo = st.top();
           char ch = topo.first;
        int freq = topo.second;
           temp+= string( freq,  ch);
           st.pop();
        }
        reverse(temp.begin(), temp.end());
        return temp;
    }
};