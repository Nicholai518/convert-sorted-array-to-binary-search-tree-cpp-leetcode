#include <iostream>
#include <vector>
using namespace std;

  struct TreeNode 
  {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
  class Solution 
  {
  public:
      TreeNode* sortedArrayToBST(vector<int>& nums) 
      {

          // No elements in vector to build tree
          if (nums.size() == 0)
          {
              return NULL;
          }

          return construct_tree(nums, 0, nums.size() - 1);
      }

      TreeNode* construct_tree(vector<int> nums, int left, int right)
      {
          // left should never be greater than right
          if (left > right)
          {
              return NULL;
          }

          // find the mid point using binary search
          int mid_point = left + (right - left) / 2;

          // asign mid point index to node
          // on the first iteration, this will be our root
          TreeNode* node = new TreeNode(nums[mid_point]);

          // now we need to assign the children node(s)
          node->left = construct_tree(nums, left, mid_point - 1);
          node->right = construct_tree(nums, mid_point + 1, right);

          return node;
      }
  };


  void printNode(TreeNode* node) 
  {
      cout << node->val << " ";

      if (node->left != NULL && node->right != NULL) 
      {
          printNode(node->left);
          printNode(node->right);
      }
  }
int main()
{
    Solution solution;

    vector<int> nums{ -10, -5, -3, 0, 5, 8, 9 };
    TreeNode* root = solution.sortedArrayToBST(nums);

    cout << "Example One : ";
    printNode(root);
	return 0;
}
