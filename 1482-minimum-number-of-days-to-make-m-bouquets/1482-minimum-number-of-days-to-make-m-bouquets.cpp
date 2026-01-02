class Solution {
public:
bool isPossible(vector<int>& bloomDay, int m, int k, int mid)
{
    int cnt = 0;
    int nob = 0;
    for(int i = 0 ; i<bloomDay.size(); i++)
    {
         if(bloomDay[i]<=mid)
         {
            cnt++;
         }
         else{
            nob+= (cnt/k);
            cnt=0;
         }
    




    }
    nob+=(cnt/k);
    return nob>=m;




}
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n= bloomDay.size();
        if((long long)m*k >n )return -1;
        int low = 1;
        int high = INT_MIN;
        for( int i =0 ; i<n; i++)
        {
            
            high = max(bloomDay[i], high);
        }
        while(low<=high)
        {
            int mid =(low+high)/2;
            if(isPossible(bloomDay , m, k, mid))
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