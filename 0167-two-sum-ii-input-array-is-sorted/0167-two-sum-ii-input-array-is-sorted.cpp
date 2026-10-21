class Solution {
public:
    vector<int> twoSum(vector<int>& n, int target) {
        int sz = n.size();
        int i = 0;
        int j = sz-1;
        vector<int>x(2,0);
      while(i<j)
      {
             int a = n[i];
             int b = n[j];
             if(a+b> target)
             {
                j--;
             }
             else if(a+b<target)
             {
                i++;
             }
             else{
               x[0]=i+1;
               x[1]=j+1;
               break;
             }
          

      }
        return x;
    }
};