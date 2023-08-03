/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    int traversal(TreeNode *node, int& ans){
        if(node == NULL)    return 0;

        int left = traversal(node->left, ans);
        int right = traversal(node->right, ans);

        if(left < 0)    left = 0;
        if(right < 0)   right = 0;
        ans = max(ans, node->val+left+right);

        return node->val+max(left, right);
    }
public:
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        traversal(root, ans);
        return ans;
    }
};
