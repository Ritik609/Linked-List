// Program to split a circular linked list
// into two halves
#include <bits/stdc++.h>
using namespace std;

/* structure for a node */
class Node
{
	public:
	int data;
	Node *next;
};

/* Function to split a list (starting with head)
into two lists. head1_ref and head2_ref are
references to head nodes of the two resultant
linked lists */
void split(Node *head,Node* &head1,Node* &head2) {
   *head1_ref = head;
    Node *curr = head;
    Node *curr2=head;
    int j=1;
    while(curr->next!=head){
        j++;
        curr = curr->next;
    }
    if(j%2==1)
        for(int i=0;i<j/2;i++)
            curr2=curr2->next;
    else
        for(int i=0;i<j/2-1;i++)
            curr2=curr2->next;
    *head2_ref=curr2->next;
    curr2->next=*head1_ref;
    curr->next=*head2_ref;
}
/*void splitList(node *head, node **head1, node **head2){
	if(head == NULL)
		return;
	*head1 = head;
	if(head->next == NULL){
		return;
	}

	node *slow = head->next;
	node *fast = head->next->next;
	while(fast->next != head && fast->next->next != head){
		slow = slow->next;
		fast = fast->next->next;
	}
	*head2 = slow->next;
	slow->next = head;
	while(fast->next != head){
		fast = fast->next;
	}
	fast->next = *head2;
}
*/
void push(Node **head_ref, int data)
{
	Node *ptr1 = new Node();
	Node *temp = *head_ref;
	ptr1->data = data;
	ptr1->next = *head_ref;
		
	/* If linked list is not NULL then
	set the next of last node */
	if(*head_ref != NULL)
	{
		while(temp->next != *head_ref)
		temp = temp->next;	
		temp->next = ptr1;
	}
	else
		ptr1->next = ptr1; /*For the first node */
	
	*head_ref = ptr1;
}

/* Function to print nodes in
a given Circular linked list */
void printList(Node *head)
{
	Node *temp = head;
	if(head != NULL)
	{
		cout << endl;
		do {
		cout << temp->data << " ";
		temp = temp->next;
		} while(temp != head);
	}
}

// Driver Code
int main()
{
	int list_size, i;
		
	/* Initialize lists as empty */
	Node *head = NULL;
	Node *head1 = NULL;
	Node *head2 = NULL;
	
	/* Created linked list will be 12->56->2->11 */
	push(&head, 12);
	push(&head, 56);
	push(&head, 2);
	push(&head, 11);
	
	cout << "Original Circular Linked List";
	printList(head);	
	
	/* Split the list */
	split(head, head1, head2);
	
	cout << "\nFirst Circular Linked List";
	printList(head1);
	
	cout << "\nSecond Circular Linked List";
	printList(head2);
	return 0;
}

// This code is contributed by rathbhupendra
