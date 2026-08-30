#include <stdlib.h>


struct ListNode* reverse(struct ListNode* head) {
    struct ListNode* prev = NULL;
    struct ListNode* curr = head;
    while (curr != NULL) {
        struct ListNode* nextTemp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextTemp;
    }
    return prev;
}
struct ListNode* removeNodes(struct ListNode* head) {
    if (head == NULL) return NULL;
    head=reverse(head);
    struct ListNode* curr = head;
    int max_val = curr->val;
    struct ListNode* prev = curr;
    curr = curr->next;
    while (curr != NULL) {
        if (curr->val < max_val){

            prev->next = curr->next;
            struct ListNode* tofree = curr;
            curr = curr->next;
            free(tofree);
        }
        else {
            
            max_val = curr->val;
            prev = curr;
            curr = curr->next;
        }

    }
    head=reverse(head);
    return head;}