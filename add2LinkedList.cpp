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
node *add(node *start,node *root){
    node *res=NULL;
    node *curr=NULL;
    
    int s=0,c=0;
    while(start or root){
        s=c+(start?start->data:0)+(root?root->data:0);
        c=s>=10?1:0;
        s=s%10;
        node *temp=new node();
        temp->data=s;
        temp->next=NULL;
        if(res==NULL){
            curr=temp;
            res=temp;
        }
        else{
            curr->next=temp;
            curr=curr->next;
        }
        if(start) start=start->next;
        if(root)root=root->next;
    }
    if(c>0){
        node *temp=new node();
        temp->data=c;
        temp->next=NULL;
        curr->next=temp;
        curr=curr->next;
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
	insert(start,9);
	insert(start,9);
	node *root=NULL;
    insert(root,9);
	insert(root,4);
	start=reverse(start);
	root=reverse(root);
	
	node *res=add(start,root);
	res=reverse(res);
	traversal(res);
	return 0;
}
