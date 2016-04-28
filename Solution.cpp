#include <stdlib.h>
using namespace std;
struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int c) : val(c), left(NULL), right(NULL) {};

};

//中序遍历
void inOrderMoriisTravel(TreeNode* root)
{
	TreeNode* current = root;
	TreeNode* pre;
	while (!current)
	{
		if (!current->left)
		{
			//visit(current);
			current = current->right;
		}
		else
		{
			pre = current->left;
			while (pre->right && pre->right != current)
			{
				pre = pre->right;
			}
			if (!pre)
			{
				pre->right = current;
				current = current->left;
			}
			else
			{
				pre->right = NULL;
				//visit(current)
				current = current->right;
			}
		}
	}
}

//前序遍历
void preOrderMoriisTravel(TreeNode* root)
{
	TreeNode *current = root;
	TreeNode *pre;
	while (current)
	{
		if (!current->left)
		{
			//visit(current);
			current = current->right;
		}
		else
		{
			pre = current->left;
			while (pre->right && pre->right != current)
			{
				pre = pre->right;
			}

			if (!pre)
			{
				//visit(current)                   //与中序遍历唯一不同的地方
				pre->right = current;
				current = current->left;
			}
			else
			{
				current = current->right;
				pre->right = NULL;
			}
		}
	}
}


//翻转指针
void reverse(TreeNode *p1, TreeNode *p2)//使用right指针翻转p1到p2节点
{
	if (p1 == p2) return;

	TreeNode *pre = p1, *p = p1->right;
	while (true)
	{
		TreeNode *tem = p->right;
		p->right = pre;
		if (p == p2) break;
		pre = p, p = tem;
	}
}

void print(TreeNode *p1, TreeNode *p2)//逆序打印p1到p2节点
{
	reverse(p1, p2);
	for (TreeNode *p = p2; ; p = p->right)
	{
		//printf("%d ", p->val);
		if (p == p1) break;
	}
	reverse(p2, p1);
}

//后序遍历
void postorder3(TreeNode *root)//Morris后序遍历
{
	TreeNode dummy(-1), *p = &dummy;
	dummy.left = root;
	while (p != NULL)
	{
		if (p->left == NULL)
			p = p->right;
		else
		{
			TreeNode *pre = p->left;
			while (pre->right != NULL && pre->right != p)
				pre = pre->right;

			if (pre->right == NULL)
			{
				pre->right = p;
				p = p->left;
			}
			else
			{
				pre->right = NULL;
				print(p->left, pre);
				p = p->right;
			}
		}
	}
}