#include <bits/stdc++.h>
using namespace std;
class Solution {

public:
    bool uniformArray(vector<int>& nums1) {
        int minodd=INT_MAX;
        for(int x:nums1){
          if (x % 2 != 0) {
                minodd =min(minodd, x);
            }
        }
        for (int x : nums1) {
            if (x % 2 == 0 && x< minodd && minodd != INT_MAX) {
                return false; // Even number is smaller than the smallest odd number tahole ar parity change kore full odd ba even kora jabena simple
            }
        }

return true;
        
    }
};