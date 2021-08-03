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
int middlePoint(node *start){
    node *slow=start;
    node *fast=start;
    while(fast and fast->next){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow->data;
}
int main() {
    
    node *start=NULL;
    insert(start,4);
	insert(start,9);
	insert(start,8);
	insert(start,7);
	insert(start,6);
	int res=middlePoint(start);
    cout<<res;
	return 0;
}
