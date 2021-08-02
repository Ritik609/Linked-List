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
    if(!start) return start;
    unordered_map<int,int> m;
    node *curr=start;
    m[curr->data]=1;
    node *prev=curr;
    curr=curr->next;
    while(curr){
        if(m[curr->data]){
            prev->next=curr->next->next;
        }
        else{
            m[curr->data]=1;
            
        }
        prev=curr;
        curr=curr->next;
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
    insert(start,1);
	insert(start,2);
	insert(start,2);
	insert(start,2);
	insert(start,5);
	traversal(start);
	remove(start);
	traversal(start);
	return 0;
}
