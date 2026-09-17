#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string minimizeStringValue(string s) {
        int cnt[26] = {0};
        int q_count = 0;
        for (char c : s) {
            if (c == '?') {
                q_count++;
            } else {
                cnt[c - 'a']++;
            }}
            //smallest freq diye sorting if freq same then lexicographically arranged hoy like ascii ascending order e
            priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
            for (int i = 0; i < 26; ++i) {
            pq.push({cnt[i],i});
        }
        vector<char> replacement;
        for (int i = 0; i < q_count; ++i) {
            auto [freq, idx] = pq.top();
            pq.pop();
            
            replacement.push_back('a' + idx);
            pq.push({freq + 1, idx});
        }
        sort(replacement.begin(),replacement.end());
        int j=0;
        for(char &c:s){
            if (c == '?') {
                c = replacement[j++];
            }
        }
        
        return s;
        
       

    }
};