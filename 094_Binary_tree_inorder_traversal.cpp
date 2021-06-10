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
public:
    void inorder_traverse( TreeNode* node, vector<int>& result ){
        if( node== nullptr ){
            return;
        }
        inorder_traverse( node->left, result );
        result.push_back( node->val );
        inorder_traverse( node->right, result );
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        inorder_traverse( root, result );
        return result;
    }
};

/*
DS course will probably teach this

Time Complexity
O(V+E)
Space Complexity
O(V+E) for all the stack
*/