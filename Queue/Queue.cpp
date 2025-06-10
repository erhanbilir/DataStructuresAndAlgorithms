#include <iostream>

using namespace std;

class Node {
public:
	int deger;
	Node* next;

	Node(int deger)
	{
		this->deger = deger;
		next = NULL;
	}
};

class Queue {
private:
	Node* head;
	Node* tail;
	int count;

public:
	Queue(int deger)
	{
		Node* node = new Node(deger);
		head = node;
		tail = node;
		count = 1;
	}
	
	~Queue()
	{
		Node* tmp = head;
		while (head)
		{
			head = head->next;
			delete tmp;
			tmp = head;
		}
		count = 0;
	}

	void printAll()
	{
		Node* tmp = head;
		while (tmp)
		{
			cout << tmp->deger << ", ";
			tmp = tmp->next;
		}
	}

	int getHeadValue()
	{
		if (head)
		{
			return head->deger;
		}
		return INT_MIN;
	}

	int getTailValue()
	{
		if (tail)
		{
			return tail->deger;
		}
		return INT_MIN;
	}

	int getCount()
	{
		return count;
	}

	void enqueue(int deger)
	{
		Node* node = new Node(deger);
		if (tail)
		{
			tail->next = node;
			tail = node;
		}
		else
		{
			head = node;
			tail = node;
		}
		count++;
	}

	int dequeue()
	{
		if (count == 0)
			return INT_MIN;

		Node* tmp = head;
		int deger = tmp->deger;
		if (count == 1)
		{
			head = NULL;
			tail = NULL;
		}
		else
		{
			head = head->next;
		}
		delete tmp;
		count--;
		return deger;
	}

	bool isEmpty()
	{
		if (count == 0)
			return true;
		return false;
	}
};

int main()
{
	Queue* queue = new Queue(12);

	queue->enqueue(24);
	queue->enqueue(7);
	queue->enqueue(15);

	cout << "Coming value from queue: " << queue->dequeue() << endl;

	cout << "Count: " << queue->getCount() << endl;
	cout << "Head value: " << queue->getHeadValue() << endl;
	cout << "Tail value: " << queue->getTailValue() << endl;

	queue->printAll();

	delete queue;
}