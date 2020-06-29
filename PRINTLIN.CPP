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


   //Function Definition for printing in forward order
     void forward_print(node *p)
      {
	if(p==NULL)
	   {

	     return;
	   }
	cout<<p->data<<"->";
	forward_print(p->link);
      }


  //function definition for printing in backward order
  void backward_print(node *p)
      {
	if(p==NULL)
	   {

	     return;
	   }
	backward_print(p->link);
	cout<<p->data<<"->";
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
      cout<<"\n\t\t2.Print a Linked List in forward manner";
      cout<<"\n\t\t3.Print a linked list in backward manner";
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
		backward_print(start);
		getch();
		clrscr();
		break;
	 case 2:clrscr();
		forward_print(start);
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
