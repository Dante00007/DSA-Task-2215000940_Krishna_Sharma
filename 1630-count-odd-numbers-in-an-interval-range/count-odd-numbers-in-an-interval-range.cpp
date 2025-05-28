class Solution {
public:
    int countOdds(int low, int high) {
        // Instead, notice a pattern:
        // Half the numbers from 1 to x are odd.
        // So, the count of odd numbers from 1 to x is (x + 1) / 2.
        return (high + 1) / 2 - low / 2;
    }
};