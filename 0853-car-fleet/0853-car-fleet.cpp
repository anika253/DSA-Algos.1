class Solution {
public:
    int carFleet(int target, vector<int>& pos, vector<int>& sp) {
        int n = pos.size();
        vector<pair<int , double>>h;
        for(int i = 0 ; i<n ; i++)
        {
              double time= (double)(target-pos[i])/sp[i];
               h.push_back({pos[i], time});
        }
        sort(h.rbegin(), h.rend());
        double l = 0;
        int cnt=0;
        for(auto it:h)
        {
            int a = it.first;
            double b= it.second;
            if(b>l)
            {
                l=b;
                cnt++;
            }

        }
        return cnt;
    }
};