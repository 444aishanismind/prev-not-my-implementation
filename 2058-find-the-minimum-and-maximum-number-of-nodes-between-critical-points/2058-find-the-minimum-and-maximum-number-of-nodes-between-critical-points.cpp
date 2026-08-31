#include <bits/stdc++.h>
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if (!head || !head->next || !head->next->next) return {-1, -1};
        
        vector<int> cp;
        ListNode* prev = head;
        ListNode* curr = head->next;
        int index = 1;
        
        while (curr->next != nullptr) {
            if ((curr->val > prev->val && curr->val > curr->next->val) || 
                (curr->val < prev->val && curr->val < curr->next->val)) {
                cp.push_back(index);
            }
            prev = curr;
            curr = curr->next;
            index++;
        }
        
        if (cp.size() < 2) return {-1, -1};
        
        int minDist = INT_MAX;
        for (int i = 1; i < cp.size(); i++) {
            minDist = min(minDist, cp[i] - cp[i - 1]); // min of mindist and the distance between current nd prev critical pt
        }
        
        int maxDist = cp.back() - cp.front();// max distance is obv always diff between last element of vector aka last critical node w first element of vector aka pos of first critical element
        
        return {minDist, maxDist};
    }
};