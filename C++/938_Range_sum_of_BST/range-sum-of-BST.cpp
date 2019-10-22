#include <iostream>

struct TreeNode{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x):val(x), left(nullptr), right(nullptr){}
};

class Solution{
public:
	Solution():sum(0){}
	int rangeSumBST(TreeNode* root, int L, int R);  
	int sum;
};

int Solution::rangeSumBST(TreeNode* root, int L, int R){
	if(!root){
		return 0;
	}
	if ((root->val >= L) && (root->val <= R)){
		sum += root->val;
	}
	rangeSumBST(root->left, L, R);
	rangeSumBST(root->right, L, R);
	return sum;
};

// root = [10, 5, 15, 3, 7, null, 18] L = 7, R = 15
//root = [10, 5, 15, 3, 7, 13, 18, 1, null, 6] L = 6, R = 10
int main(void){
	Solution solution;
	/*
	TreeNode tree(10);
	tree.left = new TreeNode(5);
	tree.right = new TreeNode(15);
	tree.left->left = new TreeNode(3);
	tree.left->right = new TreeNode(7);
	tree.right->left = nullptr;
	tree.right->right = new TreeNode(18);
	*/
	TreeNode tree(10);
	tree.left = new TreeNode(5);
	tree.right = new TreeNode(15);
	tree.left->left = new TreeNode(3);
	tree.left->right = new TreeNode(7);
	tree.right->left = new TreeNode(13);
	tree.right->right = new TreeNode(18);
	tree.left->left->left = new TreeNode(1);
	tree.left->left->right = nullptr;
	tree.left->right->right = new TreeNode(6);

	//std::cout << solution.rangeSumBST(&tree, 7, 15) << std::endl;
	std::cout << solution.rangeSumBST(&tree, 6, 10) << std::endl;
	int i = getchar();
	return 0;
}