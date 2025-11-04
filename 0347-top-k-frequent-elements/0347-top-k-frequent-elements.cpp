class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int , int>>pq;
        unordered_map<int,int>mpp;
        for( auto it: nums)
        {
            mpp[it]++;
        }
        for( auto it: mpp)
        {
            pq.push({it.second , it.first});
        }
        vector<int>final;
        while(k)
        {
         final.push_back( pq.top().second);
         pq.pop();
         k--;

        }
        return final;
    }
};