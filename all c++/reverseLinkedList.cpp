// C++ program to print reverse of a linked list using iterative method
#include <bits/stdc++.h>
using namespace std;

class Node
{
	public:
	int data;
	Node* next;
};

/* Function to print the reverse of the linked list using iterative method */
void printReverse(Node* head)
{
	stack<int> st;
	Node *curr = head;
	while(curr!=NULL)
	{
	st.push(curr->data);
	curr = curr->next;
	}
	while(st.empty()==false)
	{
	cout << st.top()<<" -> ";
	st.pop();
	}
}

/*UTILITY FUNCTIONS*/
/* function to print the elements of the linked list*/
void printList(Node *head)
{
Node *curr = head;
while(curr!=NULL)
{
	cout << curr->data << " -> ";
	curr = curr->next;
}
cout<<"\n";
}
/* Push a node to linked list. Note that this function
changes the head */
void push(Node** head_ref, char new_data)
{
	/* allocate node */
	Node* new_node = new Node();

	/* put in the data */
	new_node->data = new_data;

	/* link the old list off the new node */
	new_node->next = (*head_ref);

	/* move the head to point to the new node */
	(*head_ref) = new_node;
}

/* Driver code*/
int main()
{
	// Let us create linked list 1->2->3->4
	Node* head = NULL;
	push(&head, 4);
	push(&head, 3);
	push(&head, 2);
	push(&head, 1);
	printList(head);
	printReverse(head);
	return 0;
}

// This code is contributed by Abhijeet Kumar(abhijeet19403)
