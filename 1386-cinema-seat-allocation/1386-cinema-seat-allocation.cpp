#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        
        // Step 1: Group the reserved seats by their row number
        unordered_map<int, int> row_mask;
        for (const auto& seat : reservedSeats) {
            int row = seat[0];
            int col = seat[1];
            
            // Turn on the specific bit for this reserved seat column
            row_mask[row] |= (1 << col);
        }

        // Step 2: 'k' is the total number of rows that have at least one reservation
        int k = row_mask.size();

        // Step 3: Count families for completely empty rows (2 families per empty row)
        int total_families = (n - k) * 2;

        // Step 4: Create patterns (masks) for the three valid 4-seat groups
        const int LEFT_MASK   = (1 << 2) | (1 << 3) | (1 << 4) | (1 << 5); // Seats 2, 3, 4, 5
        const int RIGHT_MASK  = (1 << 6) | (1 << 7) | (1 << 8) | (1 << 9); // Seats 6, 7, 8, 9
        const int MIDDLE_MASK = (1 << 4) | (1 << 5) | (1 << 6) | (1 << 7); // Seats 4, 5, 6, 7

        // Step 5: Check each row that has reservations
        for (const auto& [row, mask] : row_mask) {
            
            // If the bitwise check is 0, it means zero seats are reserved in that group (it's free)
            bool left_free   = (mask & LEFT_MASK) == 0;
            bool right_free  = (mask & RIGHT_MASK) == 0;
            bool middle_free = (mask & MIDDLE_MASK) == 0;

            // If both outer groups are open, we can fit 2 families
            if (left_free && right_free) {
                total_families += 2;
            } 
            // If at least one group is open, we can fit 1 family
            else if (left_free || right_free || middle_free) {
                total_families += 1;
            }
            // If none are open, we add 0 families for this row
        }

        // Step 6: Return the final grand total
        return total_families;
    }
};