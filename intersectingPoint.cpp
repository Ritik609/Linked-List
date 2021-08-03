#include <bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    struct node* next;
    
    
};


int intersectPoint(node *start,node *root){
   
    node *temp1=start;
    node *temp2=root;
    int c1=0,c2=0;
    while(temp1){
        c1++;
        temp1=temp1->next;
    }
    while(temp2){
        c2++;
        temp2=temp2->next;
    }
    temp1=start;
    temp2=root;
    int diff=abs(c1-c2);
    if(c1>c2){
        for(int i=0;i<diff;i++)temp1=temp1->next;
    }
    else{
        for(int i=0;i<diff;i++)temp2=temp2->next;
    }
    while(temp1!=temp2){
        temp1=temp1->next;
        temp2=temp2->next;
    }
    if(temp1) return temp1->data;
    else return -1;
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
    
    node* newNode;
    node* head1 = new node();
    head1->data = 10;
    node* head2 = new node();
    head2->data = 3;
    newNode = new node();
    newNode->data = 6;
    head2->next = newNode;
    newNode = new node();
    newNode->data = 9;
    head2->next->next = newNode;
    newNode = new node();
    newNode->data = 15;
    head1->next = newNode;
    head2->next->next->next = newNode;
    newNode = new node();
    newNode->data = 30;
    head1->next->next = newNode;
    head1->next->next->next = NULL;
    node* intersect_node = NULL;
	int res=intersectPoint(head1,head2);
    cout<<res;
	return 0;
}
