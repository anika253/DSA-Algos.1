class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i = 0 ; i<n ; i++)
        {
            for( int j = i+1; j<n ; j++)
            {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        
        for( int i = 0 ; i<n ; i++)
        {
            int sr = 0;
            int sc = n-1;
            while(sr<=sc)
            {
                swap(matrix[i][sr], matrix[i][sc]);
                sr++;
                sc--;
            }
        }
    }
};