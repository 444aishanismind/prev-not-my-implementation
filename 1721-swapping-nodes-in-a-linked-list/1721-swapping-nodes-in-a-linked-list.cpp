/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        struct ListNode* first = head;
for (int i = 0; i < k - 1; i++) {
    first = first->next;

}
ListNode* fast = first;
ListNode* second = head;
while (fast->next != nullptr) {
    fast = fast->next;
    second = second->next;
}
fast=first;
fast->val=first->val;
int temp=fast->val;
fast->val=second->val;
second->val=temp;
return head;
        
    }
};