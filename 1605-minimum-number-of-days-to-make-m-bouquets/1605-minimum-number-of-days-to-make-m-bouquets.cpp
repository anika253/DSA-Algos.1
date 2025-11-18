class Solution {
public:
bool isPoss(vector<int>& bloomDay, int m, int k, int low , int high,int  mid)
{int n= bloomDay.size();
int cnt = 0;
int noofb = 0;
for( int i = 0 ; i<n; i++)
{ if(bloomDay[i]<=mid)
{
    cnt++;
}
else{
    noofb+= (cnt/k);
    cnt=0;
}


}
noofb+=(cnt/k);
return noofb>=m;

}
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n= bloomDay.size();
        int low = INT_MAX;
        int high = INT_MIN;
        if(
            (long long)m*k >= bloomDay.size()) return -1;
        
        for( int i =0 ; i<n ;i++)
        {
            low = min(low , bloomDay[i]);
            high = max(high, bloomDay[i]);
        }
        while(low<=high)
        {
            int mid = (low+high)/2;
            if(isPoss( bloomDay , m , k , low, high, mid))
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