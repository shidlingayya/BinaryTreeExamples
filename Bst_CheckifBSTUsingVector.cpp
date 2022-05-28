#include <iostream>
#include <vector>
#include <algorithm>
struct bst{
	int data;
	struct bst* left;
	struct bst* right;
};

class binarySearchTree{
public:
	binarySearchTree():root(nullptr){}
	bst* createNewNode(int value){
		bst* new_node = new bst;
		if (new_node != nullptr){
			new_node->data = value;
			new_node->left = nullptr;
			new_node->right = nullptr;
		}
		return new_node;
	}
	void insertNode(int value){
		root = inserNodeInBST(root, value);
	}
	void inorder(){
    	inorderBst(root);
	}

	bool checkIftreeIsBST()
	{
		std::vector<int> items{};
		getElements(root, items);
		int isBst = true;
		for (auto i = 0; i < items.size(); i++)
		{
			for (auto j = i + 1; j < items.size(); j++)
			{
				if (items[i] > items[j])
				{
					isBst = false;
					break;
				}
			}
		}
		return isBst;
	}

private:
	bst* inserNodeInBST(bst* root, int value){
		if (root == nullptr){
			return createNewNode(value);
		}
		if (value < root->data){
			root->left = inserNodeInBST(root->left, value);
		}
		else{
			root->right = inserNodeInBST(root->right, value);
		}
		return root;
	}

	void inorderBst(bst* root){
		if (root != nullptr){
			inorderBst(root->left);
			std::cout << root->data << "->";
			inorderBst(root->right);
		}
	}

	void getElements(bst* root, std::vector<int>& items)
	{
		if (root != nullptr)
		{
			getElements(root->left, items);
			items.push_back(root->data);
			getElements(root->right, items);
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
	//bst.inorder();
	if (bst.checkIftreeIsBST())
	{
		std::cout << "This is Binary Tree " << std::endl;
	}
	else
	{
		std::cout << "This is not Binary Tree" << std::endl;
	}
	return 0;
}
