class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long totalSum = 0;
        int  n = matrix.size();

        int MinA = INT_MAX;
        int Nc= 0;
        for( int i = 0 ; i< n ; i++)
        {
            for( int  j = 0; j< n; j++)
            {
                totalSum+= abs(matrix[i][j]);
                if(matrix[i][j]<0)
                {
                   Nc++;

                }
                MinA = min( MinA, abs(matrix[i][j]));
            }
        }
        
if(Nc%2!=0)
{
    totalSum -=2*MinA;

}

return totalSum;

    }
};