// struct TreeNode {
//   int val;
//   TreeNode* left;
//   TreeNode* right;
//   TreeNode(int x) : val(x), left(NULL), right(NULL) {}
// };

class Solution {
 public:
   TreeNode* invertTree(TreeNode* root);

 private:
   void DoSwap(TreeNode** node);
};

TreeNode* Solution::invertTree(TreeNode* root) {
  DoSwap(&root);
  return root;
}

void Solution::DoSwap(TreeNode** node) {
  if (*node == NULL) {
    return;
  }
  TreeNode* temp = (*node)->left;
  (*node)->left = (*node)->right;
  (*node)->right = temp;
  if ((*node)->left != NULL) {
    DoSwap(&((*node)->left));
  }
  if (right != NULL) {
    DoSwap(&((*node)->right));
  }
}
