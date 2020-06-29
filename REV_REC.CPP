#include<iostream.h>
#include<conio.h>
#include<stdlib.h>

 //Structure of Node
 struct node
   {
     int data;
     node *link;
   }*start=NULL;

 //Function Definition for the Insertion
  void insert()
   {
     int n;
     cout<<"\n\t\tEnter the node:-";
     cin>>n;
     node *ptr=new node;
     ptr->data=n;
     ptr->link=NULL;
     if(start==NULL)
      {
	start=ptr;
	ptr->link=NULL;
      }
     else
      {
	node *temp=start;
	while(temp->link!=NULL)
	 {
	   temp=temp->link;
	 }
	temp->link=ptr;
	ptr->link=NULL;
      }
     cout<<"\n\t\tNode Added Successfully";
   }

  //Function Definition for Traversal
    void traversal()
     {
       node *temp=start;
       if(start==NULL)
       {
	cout<<"\n\t\tList is empty";

       }
      else
       {
	 while(temp!=NULL)
	  {
	    cout<<temp->data<<"->";
	    temp=temp->link;
	  }
       }
     }

   //Function Definition for reversing a Linked List
     void rev(node *p)
      {
	if(p->link==NULL)
	   {
	     start=p;
	     return;
	   }
	rev(p->link);
	node *q=p->link;
	q->link=p;
	p->link=NULL;
	cout<<"\n\t\tList is reversed";
	cout<<"\n\n\t\tBy Traversing,you can see a reversed Linked List";
      }

 //Main Function
 void main()
  {
   clrscr();
   int ch;
   do
    {
      cout<<"\n\t\t\t****************Linked List***************\n\n";
      cout<<"\n\t\t1.Insert a Node";
      cout<<"\n\t\t2.Reverse a Linked List";
      cout<<"\n\t\t3.Traverse a Linked List";
      cout<<"\n\t\t4.Exit";
      cout<<"\n\t\tEnter your choice:-";
      cin>>ch;
      switch(ch)
       {
	 case 1:clrscr();
		insert();
		getch();
		clrscr();
		break;
	 case 3:clrscr();
		traversal();
		getch();
		clrscr();
		break;
	 case 2:clrscr();
		rev(start);
		getch();
		clrscr();
		break;
	 case 4:clrscr();
		exit(1);
		break;
	 default:clrscr();
		 cout<<"Invalid choice";
		 break;
       }
    }while(4);
    getch();
   }
