class Solution {
public:
struct comp{
 bool operator()(vector<int>a , vector<int>b)
 {
   return a[1]< b[1];
 }

};
    int eraseOverlapIntervals(vector<vector<int>>& i) {
        int n= i.size();
        int cnt = 0;
        int prev = 0;
        sort(i.begin(), i.end(), comp());
      for( int j = 1 ; j<n ; j++)
      {
     if(i[j][0]< i[prev][1])
     {
        cnt++;
       
     }
     else{
        prev=j;
     }




      }
      return cnt;
    }
};