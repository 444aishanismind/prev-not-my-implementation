#include <vector>

using namespace std;

class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> result(k, 0);
        vector<int> dp(k, 0);
        
        for (int num : nums) {
            vector<int> next(k, 0);
            int value = num % k;
            
            
            next[value]++;
            
            
            for (int r = 0; r < k; r++) {
                if (dp[r] > 0) {
                    int newRemainder = (r * value) % k;
                    next[newRemainder] += dp[r];
                }
            }
            
            
            for (int r = 0; r < k; r++) {
                result[r] += next[r];
            }
            
            dp = next;
        }
        
        return result;
    }
};