# 递归法
```
class Solution1 {
public:
	vector<int> inorderTraversal (TreeNode* root) {
		vector<int> ret;
		if (root == NULL) return ret;
		inorderHelper(ret, root);
		return ret;
	}
private:
	void inorderHelper(vector<int>& ret, TreeNode* root)
	{
		if(root == NULL) return;
		inorderHelper(ret, root->left);
		ret.push_back(root->val);
		inorderHelper(ret, root->right);
	}
}
```
# 迭代法

# Morris