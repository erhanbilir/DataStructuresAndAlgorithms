#include <iostream>

using namespace std;

class Node {
public:
	int deger;
	Node* next;
	Node* prev;

	Node(int deger)
	{
		this->deger = deger;
		next = NULL;
		prev = NULL;
	}
};

class DoublyLinkedList {
private:
	Node* head;
	Node* tail;
	int count;

public:
	DoublyLinkedList(int deger) 
	{
		Node* node = new Node(deger);
		head = node;
		tail = node;
		count = 1;
	}
	~DoublyLinkedList()
	{
		Node* tmp = head;
		while (head)
		{
			head = head->next;
			delete tmp;
			tmp = head;
		}
	}
	void printList() 
	{
		Node* tmp = head;
		while (tmp != NULL) {
			cout << tmp->deger << ", ";
			tmp = tmp->next;
		}
		cout << endl;
	}
	void printHead() 
	{
		if (head != NULL)
			cout << "Head: " << head->deger << endl;
	}
	void printTail() 
	{
		if (tail != NULL)
			cout << "Tail: " << tail->deger << endl;
	}
	void getCount() 
	{
		cout << "List count: " << count << endl;
	}
	void appendList(int deger) 
	{
		Node* node = new Node(deger);
		if (count == 0) 
		{
			head = node;
			tail = node;
		}
		else
		{
			tail->next = node;
			node->prev = tail;
			tail = node;
		}
		count++;
	}
	void deleteLastNode()
	{
		if (count == 0)
		{
			return;
		}
		Node* tmp = tail;
		if (count != 1)
		{
			tail = tail->prev;
			tail->next = NULL;
		}
		else if (count == 1)
		{
			head = NULL;
			tail = NULL;
		}
		delete tmp;
		count--;
	}
	void addFirst(int deger)
	{
		Node* node = new Node(deger);
		if (count == 0)
		{
			head = node;
			tail = node;
		}
		else
		{
			head->prev = node;
			node->next = head;
			head = node;
		}
		count++;
	}
	void deleteFirst()
	{
		if (count == 0)
		{
			return;
		}

		Node* tmp = head;
		if (count == 1)
		{
			head = NULL;
			tail = NULL;
		}
		else
		{
			head = head->next;
			head->prev = NULL;
		}
		delete tmp;
		count--;
	}
	Node* getNode(int index)
	{
		if (index < 0 || index >= count)
		{
			return NULL;
		}

		Node* tmp = tail;
		if (index >= (count/2))
		{
			for (int i = (count - 1); i > index; i--)
			{
				tmp = tmp->prev;
			}
		}
		else
		{
			tmp = head;
			for (int i = 0; i < index; i++)
			{
				tmp = tmp->next;
			}
		}
		return tmp;
	}
	bool setNode(int index, int deger)
	{
		Node* temp = getNode(index);
		if (temp != NULL)
		{
			temp->deger = deger;
			return true;
		}
		return false;
	}
	bool insertNode(int index, int deger)
	{
		if(index >= 0 || index <= count)
		{
			if (index == 0)
			{
				addFirst(deger);
				return true;
			}
			else if (index == count)
			{
				appendList(deger);
				return true;
			}

			Node* newNode = new Node(deger);
			Node* leftNode = getNode(index - 1);
			Node* rightNode = getNode(index);
			leftNode->next = newNode;
			newNode->prev = leftNode;
			rightNode->prev = newNode;
			newNode->next = rightNode;
			count++;
			return true;
		}
		else
			return false;
	}
	bool deleteNode(int index)
	{
		if (index >= 0 || index < count)
		{
			if (index == 0)
			{
				deleteFirst();
				return true;
			}
			else if (index == (count-1))
			{
				deleteLastNode();
				return true;
			}

			Node* leftNode = getNode(index - 1);
			Node* rightNode = getNode(index + 1);
			Node* tmp = getNode(index);
			leftNode->next = rightNode;
			rightNode->prev = leftNode;
			delete tmp;
			count--;
			return true;
		}
		return false;


	}
};

int main()
{
	DoublyLinkedList* doublyLinkedList = new DoublyLinkedList(12);
	doublyLinkedList->printList();
	doublyLinkedList->appendList(5);
	doublyLinkedList->appendList(24);
	doublyLinkedList->appendList(36);
	
	cout << "------" << endl;
	doublyLinkedList->printList();
	doublyLinkedList->setNode(3, 100);
	cout << "------" << endl;
	doublyLinkedList->printList();
	doublyLinkedList->insertNode(3, 200);
	cout << "------" << endl;
	doublyLinkedList->printList();
	doublyLinkedList->deleteNode(2);
	cout << "------" << endl;
	doublyLinkedList->printList();

	delete doublyLinkedList;
	return 0;
}