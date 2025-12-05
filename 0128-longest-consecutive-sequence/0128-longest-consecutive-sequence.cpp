class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>st;
        int n= nums.size();
        int lng = 0;
        for( auto it: nums)
        {
            st.insert(it);
        }
        
     for( auto it: st)
     {
      if(st.find(it-1)== st.end())
        {
            int x = it;
            int cnt = 1;
            while(st.find(x+1)!= st.end())
            {
                cnt++;
                x=x+1;
            }

          lng = max(lng , cnt);

        }
     }



return lng;

    }
};