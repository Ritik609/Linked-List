#include <bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    struct node* next;
    
    
};

node *reverse(node *start){
    
    node *prev=NULL;
    node *next;
    node *curr=start;
    while(curr!=NULL ){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    
    return prev;
}
node *add1(node *start){
    node *curr=start;
    while(curr){
        if(curr->data==9 and curr->next==NULL){
            curr->data=1;
            node *temp=new node();
            temp->data=0;
            temp->next=start;
            start=temp;
            curr=curr->next;
            
            
        }
        else if(curr->data==9){
            curr->data=0;
            curr=curr->next;
        }
        else{
            curr->data=curr->data+1;
            break;
        }
    }
    return start;
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
    insert(start,2);
	insert(start,4);
	insert(start,8);
	start=reverse(start);
	start=add1(start);
	start=reverse(start);
	traversal(start);
	return 0;
}
