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

void deleteLoop(node *start){
    node *slow,*fast;
    slow=start;
    fast=start;
    while(fast and fast->next){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast){
            break;
        }
   
    }
    if(slow==fast){
        slow=start;
        while(slow->next!=fast->next){
            slow=slow->next;
            fast=fast->next;
        }
        fast->next=NULL;
    }
    else if(slow==start){
        while(fast->next!=slow){
            fast=fast->next;
            
        }
        fast->next=NULL;
    }
    else{
        cout<<"Loop does not present";
    }

}
void isLoop(node *start){
    node *slow,*fast;
    slow=start;
    fast=start;
    while(fast and fast->next){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast){
            std::cout << "True" << std::endl;
            return;
        }
   
    }
    cout<<"False";
    return;
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
    node *temp=start;
    temp=temp->next->next;
    temp->next->next=temp;
    deleteLoop(start);
    isLoop(start);
	return 0;
}
