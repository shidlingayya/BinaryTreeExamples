#include <iostream>
#include <vector>
#include <algorithm>
struct bst
{
	int data;
	struct bst* left;
	struct bst* right;
};

class binarySearchTree
{
public:
	binarySearchTree():root(nullptr){}
	bst* createNewNode(int value)
	{
		bst* new_node = new bst;
		if (new_node != nullptr)
		{
			new_node->data = value;
			new_node->left = nullptr;
			new_node->right = nullptr;

		}
		return new_node;
	}

	void insertNode(int value)
	{
		root = inserNodeInBST(root, value);
	}

	void inorder()
	{
    	inorderBst(root);
	}

private:
	bst* inserNodeInBST(bst* root, int value)
	{
		if (root == nullptr)
		{
			return createNewNode(value);
		}
		if (value < root->data)
		{
			root->left = inserNodeInBST(root->left, value);
		}
		else
		{
			root->right = inserNodeInBST(root->right, value);
		}
		return root;
	}

	void inorderBst(bst* root)
	{
		if (root != nullptr)
		{
			inorderBst(root->left);
			std::cout << root->data << "->";
			inorderBst(root->right);
		}
	}

	bst* root;
};

int main() 
{
	binarySearchTree bst;
	bst.insertNode(8);
	bst.insertNode(3);
	bst.insertNode(1);
	bst.insertNode(6);
	bst.insertNode(7);
	bst.insertNode(10);
	bst.insertNode(14);
	bst.insertNode(4);
	bst.inorder();
	return 0;
}
