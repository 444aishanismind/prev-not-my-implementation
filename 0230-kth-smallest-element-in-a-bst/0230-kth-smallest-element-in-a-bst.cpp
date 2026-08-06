#include <bits/stdc++.h>
class Solution {
private:
    int count = 0;
    int result = -1;

    void inorder(TreeNode* root, int k) {
        if (!root || count >= k) return;
        
     
        inorder(root->left, k);
        
       
        count++;
        if (count == k) {
            result = root->val;
            return;
        }
        
       
        inorder(root->right, k);
    }

public:
    int kthSmallest(TreeNode* root, int k) {
        count = 0;
        inorder(root, k);
        return result;
    }
};