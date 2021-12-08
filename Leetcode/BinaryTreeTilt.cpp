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
    int sumLeft = 0, sumRight = 0, ans = 0;

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

    int sumTree(TreeNode *tree) {
        if (tree == nullptr) return 0;
        int sumLeft = sumTree(tree->left);
        int sumRight = sumTree(tree->right);
        int tilt = abs(sumLeft - sumRight);
        ans += tilt;
        return tree->val + sumLeft + sumRight;
    }


public:
    int findTilt(TreeNode *root) {
        sumTree(root);
        return ans;
    }

    void work() {
        vi root = {21, 7, 14, 1, 1, 2, 2, 3, 3};
        buildTree(root);
        int res = findTilt(tree);
        cout << "res";
    }
};