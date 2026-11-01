class Solution {
public:
    int minMoves(vector<int>& nums) {
        int min_val = INT_MAX;
      
        for (int x : nums) {
            min_val = min(min_val, x);
        }
        
     
        long long total_moves = 0;
        for (int x : nums) {
            total_moves += (x - min_val);
        }
        
        return (int)total_moves;
    }
};