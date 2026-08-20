#include <vector>
class Solution {
public:
    std::vector<int> resultArray(std::vector<int>& nums) {
        // Initialize r1 and r2 with the first two elements
        std::vector<int> r1 = {nums[0]};
        std::vector<int> r2 = {nums[1]};
        
        //  Loop through the rest of the elements starting at index 2
        for (int i = 2; i < nums.size(); ++i) {
            if (r1.back() > r2.back()) {
                r1.push_back(nums[i]);
            } else {
                r2.push_back(nums[i]);
            }
        }
        
        //  Combine r2 onto the end of r1 and return
        r1.insert(r1.end(), r2.begin(), r2.end());
        
        return r1;
    }
};