class Solution {
public:
bool isPossible( int low , int high , int mid ,int days , vector<int>& w )
{
    int cnt = 0;
    int wt = 0;
     int n = w.size();
    for( int i = 0; i<n ; i++)
    {
        if(wt+w[i]> mid)
        {
           cnt++;
           wt= w[i];
        }
        else{
            wt = wt+w[i];
           
        }
    }
    cnt++;
    return cnt<= days;
}
    int shipWithinDays(vector<int>& w, int days) {
        int n = w.size();
        int low = INT_MIN;
        int high = 0;
        for( int i = 0 ; i<n ; i++)
        {
            low= max( low , w[i]);
            high+= w[i];
        }
        while( low<= high)
        {
            int mid = ( low+high)/2;
            if( isPossible( low , high , mid, days, w))
            {
                high = mid-1;
            }
            else{
                low= mid+1;
            }
        }
        return low;
    }
};