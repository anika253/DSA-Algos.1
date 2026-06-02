class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>st;
        st.insert(wordList.begin(), wordList.end());
        queue<pair<string, int>>q;
        q.push({beginWord, 1});
        st.erase(beginWord);
        int steps =0;
        while(!q.empty())
        {
            auto topo = q.front();
            q.pop();
            
            
            string s = topo.first;
            int final = topo.second;
            if(s==endWord)return final;

        
            for( int i = 0 ; i<s.size(); i++)
            {
                char temp  =s[i];
                for( char  ch = 'a'; ch<='z'; ch++)
                {
                      s[i]= ch;
                      if(st.find(s)!= st.end())
                      {
                        q.push({s, final+1});
                        st.erase(s);
                      }
                }
                s[i]=temp;
            }
        }
        
         

return 0;


    }
};