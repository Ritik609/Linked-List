#include <bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    struct node* next;
    
    
};


node *intersection(node *start,node *root){
    node *res=NULL;
    node *curr=NULL;
    node *temp1=start;
    node *temp2=root;
    while(temp1 and temp2){
    if(temp1->data==temp2->data){
        node *ptr=new node;
        ptr->data=temp1->data;
        ptr->next=NULL;
        if(!res){
            res=ptr;
            curr=ptr;
        }
        else{
         curr->next=ptr;
         curr=curr->next;
        }
        temp1=temp1->next;
        temp2=temp2->next;
    }
    else if(temp1->data<temp2->data){    
        temp1=temp1->next;
        
    }
    else{
        temp2=temp2->next;
    }
   
 }
  return res;
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
    insert(start,4);
	insert(start,5);
	insert(start,9);
	node *root=NULL;
    insert(root,4);
	insert(root,5);
	insert(root,9);
	node *res=intersection(start,root);
	traversal(res);
	return 0;
}
