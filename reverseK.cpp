#include <bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    struct node* next;
    
    
};

node *reverseK(node *start,int k){
    
    node *prev=NULL;
    node *next;
    node *curr=start;
    int c=0;
    while(curr!=NULL && c<k){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
        c++;
    }
    if(next!=NULL){
        start->next=reverseK(next,k);
    }
    return prev;
}
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
void traversal(node *start){
    node *temp=start;
    while(temp!=NULL){
        std::cout << temp->data << "->";
        temp=temp->next;
    }
    
}
int main() {
    node *start=NULL;
    insert(start,1);
	insert(start,2);
	insert(start,3);
	insert(start,4);
	insert(start,5);
	insert(start,6);
	insert(start,7);
	insert(start,8);
	int k=3;
	start=reverseK(start,k);
	traversal(start);
	return 0;
}
