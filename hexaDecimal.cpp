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
//unsigned int is used to handle negative numbers correctly by treating them as large positive values in hexadecimal representation.
// This ensures that the hexadecimal conversion works as expected for both positive and negative integers.
// The main function tests the toHex method with various integer inputs, including edge cases like 0 and negative numbers
/*

int x=-1;
unsigned int y= x;
cout << x<<endl; //-1
cout << y<< endl;//2s complement representation of -1









*/