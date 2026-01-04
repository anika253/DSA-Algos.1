class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int finalSum = 0;

        for (int x : nums) {
            int cnt = 0;
            int sum = 0;

            for (int d = 1; d * d <= x; d++) {
                if (x % d == 0) {
                    int d1 = d;
                    int d2 = x / d;

                    if (d1 == d2) {
                        cnt++;
                        sum += d1;
                    } else {
                        cnt += 2;
                        sum += d1 + d2;
                    }

                    if (cnt > 4) break;
                }
            }

            if (cnt == 4) {
                finalSum += sum;
            }
        }

        return finalSum;
    }
};
