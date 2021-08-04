#include <bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    struct node* next;
    
    
};

bool isPalindrome(node *start){
    node *slow=start;
    node *fast=start;
    while(fast and fast->next){
        slow=slow->next;
        fast=fast->next->next;
    }
    node *prev=NULL;
    node *nex;
    node *curr=slow;
    
    while(curr!=NULL){
        nex=curr->next;
        curr->next=prev;
        prev=curr;
        curr=nex;
    }
    fast=start;
    while(prev){
        if(fast->data!=prev->data) return false;
        else{
            prev=prev->next;
            fast=fast->next;
        }
    }
    return true;
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

int main() {
    node *start=NULL;
    insert(start,1);
	insert(start,2);
	insert(start,3);
	insert(start,4);
	insert(start,3);
	insert(start,2);
	insert(start,2);
	cout<<isPalindrome(start);
	return 0;
}
