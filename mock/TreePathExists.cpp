#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

unordered_map<int, int> in_index;  // Map for in-order traversal index

TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder, int in_start, int in_end, int post_start, int post_end) {
    if (in_start > in_end || post_start > post_end) {
        return nullptr;
    }

    int root_val = postorder[post_end];
    TreeNode* root = new TreeNode(root_val);
    int in_root_index = in_index[root_val];

    int left_size = in_root_index - in_start;
    int right_size = in_end - in_root_index;

    root->left = buildTree(inorder, postorder, in_start, in_root_index - 1, post_start, post_start + left_size - 1);
    root->right = buildTree(inorder, postorder, in_root_index + 1, in_end, post_start + left_size, post_end - 1);

    return root;
}

bool hasPath(TreeNode* root, int target) {
    if (!root) {
        return false;
    }

    if (!root->left && !root->right) {
        return root->val == target;
    }

    return hasPath(root->left, target - root->val) || hasPath(root->right, target - root->val);
}

int main() {
    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        vector<int> inorder, postorder;
        string inorder_str, postorder_str;
        cin >> inorder_str >> postorder_str;
        
        for (char c : inorder_str) {
            if (isdigit(c)) {
                inorder.push_back(c - '0');
            }
        }
        
        for (char c : postorder_str) {
            if (isdigit(c)) {
                postorder.push_back(c - '0');
            }
        }

        int in_size = inorder.size();
        for (int j = 0; j < in_size; j++) {
            in_index[inorder[j]] = j;
        }

        TreeNode* root = buildTree(inorder, postorder, 0, in_size - 1, 0, in_size - 1);

        int T;
        cin >> T;

        for (int j = 0; j < T; j++) {
            int target;
            cin >> target;
            bool result = hasPath(root, target);
            cout << (result ? "TRUE" : "FALSE") << endl;
        }
    }

    return 0;
}
