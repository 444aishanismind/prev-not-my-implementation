#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumLengthSubstring(string s) {
        int ans = 0;
        unordered_map<char, int> countMap;
        
        int l = 0;
        for (int r = 0; r < s.length(); ++r) {
           
            countMap[s[r]]++;
            
           
            while (countMap[s[r]] > 2) {
                countMap[s[l]]--;
                l++;
            }
            
           
            ans = max(ans, r - l + 1);
        }
        
        return ans;
    }
};