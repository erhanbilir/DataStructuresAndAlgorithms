#include <iostream>

using namespace std;

class Node {
public:
	int deger;
	Node* right;
	Node* left;

	Node(int deger)
	{
		this->deger = deger;
		right = NULL;
		left = NULL;
	}
};

class BinarySearchTree {
public:
	Node* root;

	BinarySearchTree()
	{
		root = NULL;
	}

	~BinarySearchTree() 
	{
		deleteAllNodes(root);
	}

	void deleteAllNodes(Node* node)
	{
		if (node == NULL)
			return;
		// Recursive delete for left and right children
		if (node->left != NULL)
		{
			deleteAllNodes(node->left);
		}
		if (node->right != NULL)
		{
			deleteAllNodes(node->right);
		}
		delete node;
	}

	bool insertNode(int deger)
	{
		Node* node = new Node(deger);

		if (root == NULL)
		{
			root = node;
			return true;
		}
		else if (root)
		{
			Node* tmp = root;
			while (true)
			{
				if (node->deger == tmp->deger)
				{
					cout << "Node zaten bulunuyor..." << endl;
					delete node;
					return false;
				}

				if (node->deger > tmp->deger)
				{
					if (tmp->right == NULL)
					{
						tmp->right = node;
						return true;
					}
					tmp = tmp->right;
				}
				else
				{
					if (tmp->left == NULL)
					{
						tmp->left = node;
						return true;
					}
					tmp = tmp->left;
				}
			}
		}
		delete node; // Delete the node if it was not inserted
	}

	void DFSPreOrderSearchPrintAllNodes(Node* node)
	{
		if (node == NULL)
		{
			return;
		}
		cout << node->deger << endl;
		if (node->left != NULL)
		{
			cout << "/" << endl;
			DFSPreOrderSearchPrintAllNodes(node->left);
		}
		if (node->right != NULL)
		{
			cout << "\\" << endl;
			DFSPreOrderSearchPrintAllNodes(node->right);
		}
		cout << "-------------" << endl;

	}

	Node* DFSPreOrderSearch(Node* node, int value)
	{
		if(node == NULL || node->deger == value)
		{
			return node;
		}
		// If the value is less than the current node's value, search in the left subtree
		if( value < node->deger )
		{
			return DFSPreOrderSearch(node->left, value);
		}
		else
		{
			return DFSPreOrderSearch(node->right, value);
		}
	}

};

int main()
{
	BinarySearchTree* bst = new BinarySearchTree();
	bst->insertNode(52);
	cout << "root: " << bst->root->deger << endl;
	bst->insertNode(27);
	bst->insertNode(15);
	bst->insertNode(30);
	bst->insertNode(78);
	bst->insertNode(65);
	bst->insertNode(53);

	bst->insertNode(76);

	cout << "son eklenen node: " << bst->root->right->left->right->deger << endl;

	bst->insertNode(12);

	cout << "son eklenen node: " << bst->root->left->left->left->deger << endl;
	
	bst->DFSPreOrderSearchPrintAllNodes(bst->root);
	Node* ptr = bst->DFSPreOrderSearch(bst->root, 42);
	if (ptr != NULL)
	{
		cout << "Aranan deger: " << ptr->deger << endl;
	}
	else
	{
		cout << "Aranan deger bulunamadi" << endl;
	}
	delete ptr;

	delete bst;
	bst->DFSPreOrderSearchPrintAllNodes(bst->root);
	return 0;
}