#include <bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    struct node* next;
    
    
};

void insert(node* &head,int x){
  node* ptr = new node();

	/* put in the data */
	ptr->data = x;
    ptr->next=NULL;
	if(head==NULL){
	    head=ptr;
	}
	else{
	    node *temp=head;
	    while(temp->next){
	        temp=temp->next;
	    }
	    temp->next=ptr;
	    
	}
}
node *merge(node *head1,node *head2){
    node *res=new node();
    node *temp=res;
    while(head1 and head2){
        if(head1->data<=head2->data){
            temp->next=head1;
            head1=head1->next;
            temp=temp->next;
        }
        else{
            temp->next=head2;
            head2=head2->next;
            temp=temp->next;
        }
    }
    while(head1){
        temp->next=head1;
        head1=head1->next;
        temp=temp->next;    
    }
    while(head2){
        temp->next=head2;
        head2=head2->next;
        temp=temp->next;
    }
    return res->next;
}
node *middlePoint(node *start){
    node *slow=start;
    node *fast=start;
    while(fast and fast->next){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}
node *mergeSort(node *head){
     if (head->next == NULL)
            return head;
 
        node *mid = middlePoint(head);
        node *head2 = mid->next;
        mid->next = NULL;
        node *newHead1 = mergeSort(head);
        node *newHead2 = mergeSort(head2);
        node *finalHead = merge(newHead1, newHead2);
 
        return finalHead;
}


node *traversal(node *res){
    node *temp=res;
    while(temp){
        std::cout << temp->data<<"->";
        temp=temp->next;
    }
}
int main() {
    node *root=NULL;
	insert(root,3);
	insert(root,15);
	insert(root,9);
	insert(root,7);
	insert(root,4);
	node *res=mergeSort(root);
    traversal(res);
	return 0;
}
