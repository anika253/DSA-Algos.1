class Solution {
public:
    long long minOperations(vector<vector<int>>& queries) {
        auto getOperations = [](long long n) -> long long {
            if (n < 0) return 0;
            long long total = 0;
            long long base = 1;
            int k = 1;
            while (base <= n) {
                long long next_base = base * 4;
                long long count = min(next_base - 1, n) - base + 1;
                if (count > 0) {
                    total += count * k;
                }
                base = next_base;
                k++;
            }
            return total;
        };
        
        long long result = 0;
        for (auto& q : queries) {
            int l = q[0], r = q[1];
            long long ops_r = getOperations(r);
            long long ops_l_minus = getOperations(l - 1);
            long long total_ops = ops_r - ops_l_minus;
            result += (total_ops + 1) / 2;
        }
        return result;
    }
};