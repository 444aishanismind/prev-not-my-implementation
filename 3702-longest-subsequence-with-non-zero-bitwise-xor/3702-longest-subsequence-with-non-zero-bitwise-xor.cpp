class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
     int totalxor = 0;
bool hasnonzero = false;
int n = nums.size();

for (int x:nums) {
    totalxor ^= x;
    if (x != 0) {
        hasnonzero = true;
    }
}


if (totalxor != 0) return n;
if (!hasnonzero) return 0;
return n - 1;
        
    }
};