class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n = wordList.size();
        unordered_set<string>st(wordList.begin(), wordList.end());
        queue<pair<string, int>>q;
        q.push({beginWord, 1});
        st.erase(beginWord);
        while(!q.empty())
        {
            auto topo = q.front();
            q.pop();
            string t = topo.first;
            int u = topo.second;
            if( t==endWord)
            {
                return u;
            }
            for( int i = 0 ; i<t.size(); i++)
            {
                char original = t[i];
                for( char ch='a'; ch<='z' ;ch++)
                {
                   t[i]= ch;
                   if(st.find(t)!= st.end())
                   {
                    st.erase(t);
                    q.push({t,u+1});
                   }
                }
                t[i]= original;
            }
        }
        return 0;
    }
};