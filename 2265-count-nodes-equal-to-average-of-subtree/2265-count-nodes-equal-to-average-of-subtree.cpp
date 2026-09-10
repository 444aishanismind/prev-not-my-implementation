using namespace std;

class Solution {
private:
    int validCount = 0;

   
    pair<int, int> dfs(TreeNode* root) {
        if (!root) return {0, 0};

      
        auto left = dfs(root->left);
        auto right = dfs(root->right);

        int totalSum = left.first + right.first + root->val;
        int totalNodes = left.second + right.second + 1;

      
        if (totalSum / totalNodes == root->val) {
            validCount++;
        }

    
        return {totalSum, totalNodes};
    }

public:
    int averageOfSubtree(TreeNode* root) {
        validCount = 0;
        dfs(root);
        return validCount;
    }
};