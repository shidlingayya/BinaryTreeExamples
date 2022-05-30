#include <iostream>
struct bst
{
	int data;
	bst* left;
	bst* right;
};

class binSearchTree
{
public:
	binSearchTree():root(nullptr){}
	bst* getNewNode(int value){
		bst* new_node = new bst;
		if (new_node){
			new_node->data = value;
			new_node->left = nullptr;
			new_node->right = nullptr;
		}
		return new_node;
	}

	void insertNode(int value)
	{
		root = insertNodeBst(root, value);
	}

	void display()
	{
		displayBstInorder(root);
	}

	bool searchNode(int value)
	{
		bst* copy_of_root = root;
		while (copy_of_root != nullptr)
		{
			if (copy_of_root->data == value)
			{
				return true;
			}
			//If root is greater than element must be in Left hand side of BST
			if (copy_of_root->data > value)
			{
				copy_of_root = copy_of_root->left;
			}
			else //If root is lesser than element must be in Right hand side of BST
			{
				copy_of_root = copy_of_root->right;
			}			
		}
		return false;
	}

private:
	bst* insertNodeBst(bst* root, int value)
	{
		if (root == nullptr)
		{
			return getNewNode(value);
		}

		if (value < root->data)
		{
			root->left = insertNodeBst(root->left, value);
		}
		else
		{
			root->right = insertNodeBst(root->right, value);
		}
		return root;
	}

	void displayBstInorder(bst* root)
	{
		if (root != nullptr)
		{
			displayBstInorder(root->left);
			std::cout << root->data << " ";
			displayBstInorder(root->right);
		}
	}
	bst* root;
};


int main() 
{
	binSearchTree bst;
	bst.insertNode(10);
	bst.insertNode(3);
	bst.insertNode(5);
	bst.insertNode(100);
	bst.insertNode(30);
	bst.display();
	std::cout << std::endl;
	if (bst.searchNode(5))
	{
		std::cout << "Element found in bst" << std::endl;
	}
	else
	{
		std::cout << "Element not found in bst" << std::endl;
	}

	if (bst.searchNode(200))
	{
		std::cout << "Element found in bst" << std::endl;
	}
	else
	{
		std::cout << "Element not found in bst" << std::endl;
	}
	return 0;
}