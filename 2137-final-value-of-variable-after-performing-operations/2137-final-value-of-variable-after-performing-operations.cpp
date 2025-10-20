class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int n = operations.size();
        int cnt = 0;
        for( auto it: operations)
        {
           if( it =="X++" || it =="++X")
           {
            cnt++;
           }
           else if( it=="--X" || it =="X--")
           {
            cnt--;
           }
        }
        return cnt;
    }
};