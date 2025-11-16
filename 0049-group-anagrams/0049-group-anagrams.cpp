class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>>mpp;
        for( auto it: strs)
        {
            string st = it;
            sort(st.begin(), st.end());
            mpp[st].push_back(it);
        }
        vector<vector<string>>final;
        for( auto it:mpp)
        {
            final.push_back(it.second);
        }
        return final;

    }
};