class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return false;
        
        vector<int> min_left(n);
        min_left[0] = nums[0];
        for (int i = 1; i < n; ++i) {
            min_left[i] = min(min_left[i-1], nums[i]);
        }
        
        set<int> right_elements;
        right_elements.insert(nums[n-1]);
        
        for (int j = n-2; j > 0; --j) {
            if (min_left[j-1] < nums[j]) {
                auto it = right_elements.upper_bound(min_left[j-1]);
                if (it != right_elements.end() && *it < nums[j]) {
                    return true;
                }
            }
            right_elements.insert(nums[j]);
        }
        
        return false;
    }
};