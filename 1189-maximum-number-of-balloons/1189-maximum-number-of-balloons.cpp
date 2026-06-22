class Solution {
public:
    int maxNumberOfBalloons(string text) {
        
        int n = text.size();
        unordered_map<char , int>mpp;
        for(auto it: text)
        {
            if(it=='b' || it=='a' || it =='l' || it == 'o' || it =='n')
            {
              mpp[it]++;
            }
        }

    
        int a = mpp['b'];
        int b = mpp['a'];
        int c = mpp['l'];
        int d = mpp['o'];
        int e = mpp['n'];
        
       int f = min({a, b, c/2, d/2, e});
       return f;
    }
};