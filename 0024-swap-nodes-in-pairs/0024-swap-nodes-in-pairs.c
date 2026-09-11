/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* swapPairs(struct ListNode* head) {
    
    if(!head||!head->next) return head;
    struct ListNode dummy;
    dummy.next = head;
    struct ListNode *prev=&dummy ;//dummy is created as a regular local variable (on the stack), not as a pointer.
    struct ListNode *first = head;
    struct ListNode *sec = head->next;
    while(first && sec){
        struct ListNode *rest=sec->next;
        
        sec->next=first;
        first->next=rest;
        prev->next=sec;
        prev=first;
        first=prev->next;
if(first)
    sec=first->next;
else
sec=NULL;

    }
    return dummy.next;

}