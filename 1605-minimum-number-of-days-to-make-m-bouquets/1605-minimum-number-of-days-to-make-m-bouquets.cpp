class Solution {
public:
bool isPossible( int low , int high , int mid , int k ,int m ,  vector<int>& bloomDay )
{
    int cnt = 0;
    int noofB = 0;
     int n = bloomDay.size();
     for( int i = 0 ; i<n ; i++)
     {
        if( bloomDay[i]<= mid)
        {
            cnt++;
            
        }
        else{
           noofB+= (cnt/k);
           cnt=0;
        }
     }
     noofB +=(cnt/k);
     return noofB>=m;
}
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        int low = INT_MAX;
        int high = INT_MIN;
        if((long long)m*k >bloomDay.size())return -1;
        for( int i = 0 ; i<n ; i++)
        {
            low = min( low , bloomDay[i]);
            high = max( high , bloomDay[i]);
        }
        while(low<= high)
        {
            int mid = (low+high)/2;
            if(isPossible(low, high ,mid,k,m,  bloomDay))
            {
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return low;

    }
};