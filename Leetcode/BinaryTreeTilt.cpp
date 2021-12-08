#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class BinaryTreeTilt {
private:
    TreeNode *tree = new TreeNode(), *t;
    int sumLeft = 0, sumRight = 0;

    void buildTree(vi &arr) {
        int len = arr.size(), half = len >> 1, it = 0;
        t = tree;
        while (it < half) {
            int l = (it << 1) + 1;
            int r = l + 1;
            int rootNode = arr[it];
            int lNode = arr[l];
            int rNode = arr[r];
            t->val = rootNode;
            t->left = new TreeNode(lNode);
            t->right = new TreeNode(rNode);
            it += 1;
            findNode(arr[it], tree);
        }
    }

    void findNode(int val, TreeNode *tree) {
        if (tree != nullptr) {
            if (tree->val == val) t = tree;
            findNode(val, tree->left);
            findNode(val, tree->right);
        }
    }

    void sumLeftTree(TreeNode *tree) {
        if (tree != nullptr) {
            sumLeftTree(tree->left);
            sumLeft += tree->val;
            sumLeftTree(tree->right);
        }
    }

    void sumRightTree(TreeNode *tree) {
        if (tree != nullptr) {
            sumRightTree(tree->left);
            sumRight += tree->val;
            sumRightTree(tree->right);
        }
    }

    void sumTree(TreeNode *root) {
        if (root != nullptr) {
            sumLeftTree(root->left);
            sumRightTree(root->right);
        }
    }


public:
    int findTilt(TreeNode *root) {
        sumTree(root->left);
        int leftAns = abs(sumLeft - sumRight);
        sumLeft = 0, sumRight = 0;
        sumTree(root->right);
        int rightAns = abs(sumLeft - sumRight);
        sumLeft = 0, sumRight = 0;
        sumTree(root);
        int centerAns = abs(sumLeft - sumRight);
        return leftAns + centerAns + rightAns;
    }

    void work() {
        vi root = {21, 7, 14, 1, 1, 2, 2, 3, 3};
        buildTree(root);
        int res = findTilt(tree);
        cout << "res";
    }
};