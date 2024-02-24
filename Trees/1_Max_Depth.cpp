#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class TreeNode {
    public : 
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode() : val(0), left(nullptr), right(nullptr) {}
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int maxDepth(TreeNode* root) {
    if(!root) return 0;

    int left_max = maxDepth(root->left);
    int right_max = maxDepth(root->right);

    return 1 + max(left_max, right_max);
}

int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    int depth = maxDepth(root);
    cout << "Maximum Depth: "<< depth <<endl;

    return 0;
}