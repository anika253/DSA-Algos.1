class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n = wordList.size();
        unordered_set<string>st(wordList.begin(), wordList.end());
        queue<pair<string , int>>q;
        q.push({beginWord, 1});
        st.erase(beginWord);
        while(!q.empty())
        {
            auto topo = q.front();
            q.pop();
            string s = topo.first;
            int steps = topo.second;
            if(s==endWord)return steps;
            for(int i = 0; i<s.size(); i++)
            {
                char temp= s[i];
                for(char ch = 'a' ; ch<='z'; ch++)
                {
                    s[i]= ch;
                    if(st.find(s)!= st.end())
                    {
                      q.push({s, steps+1});
                      st.erase(s);
                    }

                }
                s[i]= temp;
            }
        }
        return 0;

    }
};