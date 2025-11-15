class Solution {
public:
    string strWithout3a3b(int a, int b) {
        priority_queue<pair<int ,char>>pq;
        if(a>0)
        {
            pq.push({a, 'a'});
        }
        if(b>0)
        {
            pq.push({b, 'b'});
        }
        string res="";
        while(!pq.empty())
        {
            int n = res.size();
            auto[cnt1, ch1]= pq.top();
            pq.pop();
            if( n>=2 && res[n-1]==ch1 && res[n-2]==ch1)
            {
                if(pq.empty()) break;
                 auto[cnt2 , ch2]= pq.top();
                 pq.pop();
                 res+= ch2;
                 cnt2--;
                 if(cnt2>0)
                 {
                    pq.push({cnt2, ch2});
                 }
                 pq.push({cnt1, ch1});
            }

         else{
            res+=ch1;
            cnt1--;
            if(cnt1>0)
            {
                pq.push({cnt1, ch1});
            }
         }
        }
        return res;
    }
};