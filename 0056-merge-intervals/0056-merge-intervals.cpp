class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& in) {
        int n = in.size();
        sort(in.begin(), in.end());
        vector<vector<int>>final;
        vector<int>x= in[0];
    
        for(int i =1 ; i<n ; i++)
        {
            if(x[1]>= in[i][0])
            {
                x[1]= max(x[1], in[i][1]);
            }
            else{
                final.push_back(x);
                x= in[i];
            }
        }
        final.push_back(x);
        return final;
    }
};