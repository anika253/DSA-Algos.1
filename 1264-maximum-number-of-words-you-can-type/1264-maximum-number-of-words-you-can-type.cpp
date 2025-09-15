#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        unordered_set<char> broken(brokenLetters.begin(), brokenLetters.end());
        stringstream ss(text);
        string word;
        int count = 0;

        while (ss >> word) {
            bool valid = true;
            for (char c : word) {
                if (broken.count(c)) {
                    valid = false;
                    break;
                }
            }
            if (valid) count++;
        }
        return count;
    }
};
