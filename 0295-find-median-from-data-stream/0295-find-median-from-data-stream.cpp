class MedianFinder {
public:
priority_queue<int>maxH;
priority_queue<int , vector<int>, greater<int>>minH;
void balanceHeaps()
{
    if(minH.size() > maxH.size())
    {
        int topo = minH.top();
        minH.pop();
        maxH.push(topo);
    }
    else if(maxH.size() >minH.size()+1)
    {
        int topo = maxH.top();
        maxH.pop();
        minH.push(topo);
    }

}
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(maxH.empty())
        {
            maxH.push(num);
            return;
        }
        else if(num > maxH.top())
        {
            minH.push(num);
        }
        else{
            maxH.push(num);
        }
        balanceHeaps();
    }
    
    double findMedian() {
        if(maxH.size()==minH.size()+1)
        {
            return maxH.top();
        }
        else{
            double ans = maxH.top()+minH.top();
            ans/=2.0;
            return ans;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */