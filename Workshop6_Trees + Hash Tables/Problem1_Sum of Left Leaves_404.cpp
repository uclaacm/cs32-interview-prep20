/*
    UCLA ACM ICPC: Interview Track Leetcode Problem Solutions

    Disclaimer: This is not the only valid solution and we do not claim our solutions 
    to be optimal in terms of runtime or memory usage, we are merely giving example 
    solutions to questions for learning purposes only

    Sum of Left Leaves
    Leetcode Problem 404
    https://leetcode.com/problems/sum-of-left-leaves/
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// Find the sum of all left leaves in a given binary tree.
class Solution {
private:
    // First, we define a helper function isLeaf, which determines
    // whether the given node is a leaf. We define a leaf to be a
    // node with no children. We also define NULL to not be a leaf.
    bool isLeaf(TreeNode* node) {
        if(node == NULL)
            return false;
        else
            return node->left == NULL && node->right == NULL;
    }
public:
    int sumOfLeftLeaves(TreeNode* root) {
        // Base case: If the root is NULL, then there aren't any
        // left leaves to sum up. Therefore, we return 0.
        if(root == NULL)
            return 0;

        // Recursive case: If the left node exists, we check if
        // it is a leaf (both of these checks are done in the
        // isLeaf function). If it is, then we add that node's value
        // to our result. To find all the other left leaves, we look
        // in the right subtree. Note that the root cannot be a left
        // leaf because it is not the left parent of any node.
        else if(isLeaf(root->left))
            return root->left->val + sumOfLeftLeaves(root->right);

        // Recursive case: If the left node doesn't exist or the left node
        // is not a leaf, then we want to search both the left and right
        // subtrees for possible left leaves. Again, note that the root connot
        // be a left leaf because it is not the left parent of any node.
        else
            return sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
    }
};

// Time Complexity Analysis:
// We examine each node at most three times: once if is ever the root of
// an examined subtree once if it is ever the left subroot of an examined
// subtree, and once if it is ever the child of a left subroot. If there are
// n nodes, then we do at most 3n examinations, meaning our runtime is O(n).