#include <bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    struct node* next;
    
    
};
void insert(node* &head, int x)
{
	/* allocate node */
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
node *remove(node *start){
   node *curr=start;
   while(curr->next){
       if(curr->next->data==curr->data){
           curr->next=curr->next->next;
       }
    else curr=curr->next;
   }
   return start;
}

void traversal(node *start){
    node *temp=start;
    while(temp!=NULL){
        std::cout << temp->data << "->";
        temp=temp->next;
    }
    cout<<endl;
}
int main() {
    node *start=NULL;
    insert(start,2);
	insert(start,2);
	insert(start,2);
	insert(start,2);
	insert(start,2);
	traversal(start);
	remove(start);
	traversal(start);
	return 0;
}
