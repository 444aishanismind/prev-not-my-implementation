#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    // Recursive function to find max score for subarray from index i to j
    int solve(int i, int j, vector<int>& stoneValue, vector<vector<int>>& memo, vector<int>& pref) {
        if (i >= j) return 0; // Base case: if 0 or 1 stone is left, score is 0
        if (memo[i][j] != -1) return memo[i][j]; // If we already calculated this subproblem, return it
        
        int maxScore = 0; // Variable to track the maximum score possible for range [i, j]
        
        // Loop through every possible split point 'k' between i and j
        for (int k = i; k < j; ++k) {
            int leftSum = pref[k + 1] - pref[i]; // Get sum of the left part using prefix sums
            int rightSum = pref[j + 1] - pref[k + 1]; // Get sum of the right part using prefix sums
            
            if (leftSum < rightSum) {
                // If left sum is smaller, Bob throws right. Alice gets leftSum plus future left score
                int currentScore = leftSum + solve(i, k, stoneValue, memo, pref);
                maxScore = max(maxScore, currentScore); // Update max score
            } 
            else if (leftSum > rightSum) {
                // If right sum is smaller, Bob throws left. Alice gets rightSum plus future right score
                int currentScore = rightSum + solve(k + 1, j, stoneValue, memo, pref);
                maxScore = max(maxScore, currentScore); // Update max score
            } 
            else {
                // If both sums are equal, Alice chooses the maximum possible score between both options
                int leftChoice = leftSum + solve(i, k, stoneValue, memo, pref);
                int rightChoice = rightSum + solve(k + 1, j, stoneValue, memo, pref);
                maxScore = max(maxScore, max(leftChoice, rightChoice)); // Take the best choice
            }
        }
        
        return memo[i][j] = maxScore; // Save the computed answer in the memo table and return it
    }
    
    // Main function called by LeetCode
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size(); // Store total number of stones
        
        // Create a memoization table filled with -1 to store already solved subproblems
        vector<vector<int>> memo(n, vector<int>(n, -1)); 
        
        // Create a prefix sum array to calculate subarray sums in O(1) time
        vector<int> pref(n + 1, 0); 
        
        // Populate the prefix sum array
        for (int i = 0; i < n; ++i) {
            pref[i + 1] = pref[i] + stoneValue[i]; 
        }
        
        // Start the recursive DP process from the first stone (0) to the last stone (n - 1)
        return solve(0, n - 1, stoneValue, memo, pref); 
    }
};