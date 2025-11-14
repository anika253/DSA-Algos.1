class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n= nums.size();
        unordered_map<int , int>mpp;
        vector<int>final;
        for(auto it: nums)
        {
            mpp[it]++;

        }
        priority_queue<pair<int, int>>pq;
        for( auto it: mpp)
        {
            pq.push({it.second, it.first});
        }
        while(k)
        {
          auto topo = pq.top();
           final.push_back(topo.second);
           pq.pop();
           k--;
        }
        return final;
    }
};