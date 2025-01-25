class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max_product = nums[0], min_product = nums[0], global_max = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            int current = nums[i];
            
            int temp_max = max({current, current * max_product, current * min_product});
            min_product = min({current, current * max_product, current * min_product});
            
            max_product = temp_max;
            global_max = max(global_max, max_product);
        }

        return global_max;
    }
};