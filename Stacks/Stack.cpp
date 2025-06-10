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

class Stack {
private:
	Node* top;
	int count;
	
public:
	Stack(int deger)
	{
		Node* node = new Node(deger);
		top = node;
		count = 1;
	}
	~Stack()
	{
		Node* tmp = top;
		while (top)
		{
			top = top->next;
			delete tmp;
			tmp = top;
		}
		count = 0;
	}
	void printStack()
	{
		Node* tmp = top;

		while (tmp != NULL)
		{
			cout << tmp->deger << endl;
			tmp = tmp->next;
		}
		cout << "-------" << endl;
	}
	void printTop()
	{
		if (top)
		{
			cout << "Top value: " << top->deger << endl;
		}
	}
	int getCount()
	{
		return count;
	}
	void push(int deger)
	{
		Node* node = new Node(deger);
		node->next = top;
		top = node;
		count++;
	}
	int pop()
	{
		Node* tmp = top;
		int deger = tmp->deger;
		if (tmp)
		{
			top = top->next;
			tmp->next = NULL;
			delete tmp;
			count--;
			return deger;
		}
		else
		{
			cout << "Stack is empty!" << endl;
			exit(-1);
		}
	}
	bool isEmpty()
	{
		return count == 0;
	}
};

int main()
{
	Stack* stack = new Stack(5);
	stack->printStack();

	stack->push(20);
	stack->push(6);
	stack->printStack();

	int deger = stack->pop();
	cout << "Popped value: " << deger << endl;
	cout << "-------" << endl;

	stack->printStack();

	if(stack->isEmpty())
		cout << "Stack is empty!" << endl;
	else
		cout << "Stack is not empty!" << endl;
	cout << "-------" << endl;

	stack->printTop();

	delete stack;
	return 0;
}