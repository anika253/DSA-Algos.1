class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& i) {
        sort(i.begin(),i.end());
        vector<vector<int>>final;
        vector<int>temp = i[0];
        for( auto it: i)
        {
            if( it[0] <= temp[1])
            {
                temp[1]= max( it[1],temp[1]);
            }
            else{
                final.push_back(temp);
                temp= it;
            }
        }
        final.push_back(temp);
        return final;
    }
};