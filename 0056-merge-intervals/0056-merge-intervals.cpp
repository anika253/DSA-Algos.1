class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& i) {
        sort(i.begin(),i.end());
        vector<int>temp= i[0];
        vector<vector<int>>final;
        for( auto it: i)
        {
            if(temp[1]>= it[0])
            {
                temp[1]=max(temp[1], it[1]);
            }
            else{
                final.push_back(temp);
                temp = it;

            }
        }
        final.push_back(temp);
        return final;
    }
};