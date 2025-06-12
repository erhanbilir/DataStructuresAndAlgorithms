#include <iostream>
#include <queue>

using namespace std;

class Node {
public:
	int value;
	Node* right;
	Node* left;

	Node(int value)
	{
		this->value = value;
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

	bool insertNode(int value)
	{
		Node* node = new Node(value);

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
				if (node->value == tmp->value)
				{
					cout << "Node already exists..." << endl;
					delete node;
					return false;
				}

				if (node->value > tmp->value)
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
		cout << node->value << endl;
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

	void DFSPostOrderSearchPrintAllNodes(Node* node)
	{
		if (node == NULL)
		{
			return;
		}
		if (node->left != NULL)
		{
			DFSPostOrderSearchPrintAllNodes(node->left);
		}
		if (node->right != NULL)
		{
			DFSPostOrderSearchPrintAllNodes(node->right);
		}
		cout << node->value << ", ";

	}

	void DFSInOrderSearchPrintAllNodes(Node* node)
	{
		if (node == NULL)
		{
			return;
		}
		if (node->left != NULL)
		{
			DFSInOrderSearchPrintAllNodes(node->left);
		}
		cout << node->value << ", ";
		if (node->right != NULL)
		{
			DFSInOrderSearchPrintAllNodes(node->right);
		}
	}

	Node* DFSPreOrderSearch(Node* node, int value)
	{
		if(node == NULL || node->value == value)
		{
			return node;
		}
		// If the value is less than the current node's value, search in the left subtree
		if( value < node->value )
		{
			return DFSPreOrderSearch(node->left, value);
		}
		else
		{
			return DFSPreOrderSearch(node->right, value);
		}
	}

	void BreadthFirstSearch()
	{
		queue<Node*> queue1;
		queue1.push(root);

		while (queue1.size() > 0)
		{
			Node* node = queue1.front();
			queue1.pop();
			cout << node->value << ", ";

			if (node->left != NULL)
			{
				queue1.push(node->left);
			}
			if (node->right != NULL)
			{
				queue1.push(node->right);
			}
		}
	}
};

int main()
{
	BinarySearchTree* bst = new BinarySearchTree();
	bst->insertNode(52);
	cout << "root: " << bst->root->value << endl;
	bst->insertNode(27);
	bst->insertNode(15);
	bst->insertNode(30);
	bst->insertNode(78);
	bst->insertNode(65);
	bst->insertNode(53);

	bst->insertNode(76);

	cout << "Last added node: " << bst->root->right->left->right->value << endl;

	bst->insertNode(12);

	cout << "Last added node: " << bst->root->left->left->left->value << endl;
	
	bst->DFSPreOrderSearchPrintAllNodes(bst->root);
	Node* ptr = bst->DFSPreOrderSearch(bst->root, 42);
	if (ptr != NULL)
	{
		cout << "Expected value: " << ptr->value << endl;
	}
	else
	{
		cout << "Expected value not found" << endl;
	}
	delete ptr;

	bst->DFSPostOrderSearchPrintAllNodes(bst->root);
	cout << endl;
	bst->DFSInOrderSearchPrintAllNodes(bst->root);
	cout << endl;
	bst->BreadthFirstSearch();
	delete bst;
	//bst->DFSPreOrderSearchPrintAllNodes(bst->root);
	return 0;
}