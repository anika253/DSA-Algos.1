#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string toHex(int num) {
        if (num == 0) return "0";

        string hexDigits = "0123456789abcdef";
        string result = "";
        unsigned int n = static_cast<unsigned int>(num); 
        while (n > 0) {
            int digit = n % 16;
            result = hexDigits[digit] + result;
            n /= 16;
        }

        return result;
    }
};

int main() {
    Solution sol;

    int nums[] = {0, 26, -1, 255, -16, -2147483648};
    int n = sizeof(nums) / sizeof(nums[0]);

    for (int i = 0; i < n; i++) {
        int input = nums[i];
        string hexStr = sol.toHex(input);
        cout << "Decimal: " << input << " → Hex: " << hexStr << endl;
    }

    return 0;
}
