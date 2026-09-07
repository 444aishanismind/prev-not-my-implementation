#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> result;
        int curr=1;
        for (int num : target) {
        while (curr < num) {
                result.push_back("Push");
                result.push_back("Pop");
                curr++;
            }
            result.push_back("Push");
            curr++;
    }
        
    return result;}
};