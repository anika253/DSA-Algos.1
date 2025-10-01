class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int total = numBottles;
        int emptyBottles = numBottles;
        
        while (emptyBottles >= numExchange) {
            int newBottles = emptyBottles / numExchange;
            total += newBottles;
            emptyBottles = newBottles + (emptyBottles % numExchange);
        }
        
        return total;
    }
};