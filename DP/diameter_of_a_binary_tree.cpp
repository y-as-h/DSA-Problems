struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */

class Solution {
  private:
    int traversal(Node *node, int& ans, map<Node*, int>& mp){
        if(node == NULL)    return 0;
        if(mp.find(node) != mp.end())   return mp[node];
        
        int left = traversal(node->left, ans, mp);
        int right = traversal(node->right, ans, mp);
        
        ans = max(ans, 1+left+right);
        
        return mp[node] = 1+max(left, right);
    }
  public:
    // Function to return the diameter of a Binary Tree.
    int diameter(Node* root) {
        int ans = 0;
        map<Node*, int> mp;
        traversal(root, ans, mp);
        
        return ans;
    }
};
