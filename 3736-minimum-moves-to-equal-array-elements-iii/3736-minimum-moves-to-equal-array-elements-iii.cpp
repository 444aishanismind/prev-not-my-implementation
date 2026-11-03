class Solution {
public:
    int minMoves(vector<int>& nums) {
        int max_val = INT_MIN;
  
        for (int x : nums) {
            if (x > max_val) {
                max_val = x;
            }
        }
    
        int moves = 0;
        for (int x : nums) {
            moves += (max_val - x);
        }
        
        return moves;
    }
};