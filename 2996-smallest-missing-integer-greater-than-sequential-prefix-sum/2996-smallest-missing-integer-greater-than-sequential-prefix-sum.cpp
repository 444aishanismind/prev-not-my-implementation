#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int missingInteger(vector<int>& nums) {
       
        int s = nums[0];
        for (size_t i = 1; i < nums.size(); ++i) {
            if (nums[i] == nums[i - 1] + 1) {
                s += nums[i];
            } else {
                break; 
            }
        }

       
        int ans = s;
        while (true) {
           
            if (find(nums.begin(), nums.end(), ans) == nums.end()) {
                return ans;
            }
            ans++;
        }
    }
};