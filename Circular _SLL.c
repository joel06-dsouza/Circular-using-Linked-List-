#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
	struct node * next;
}node;
void display(node *);
node * insert_beg(node *);
node * insert_end(node *);
node * delete_beg(node *);
node * delete_end(node *);
int main()
{
   struct node * start = NULL;
   int c;
   while(1)
   {
      printf("\nMENU:\n1.Insert_beg\n2.Insert_end\n3.Delete_beg\n4.Delete_end\n5.Display\n6.Exit\n");
	  printf("Enter the choice: \n");
	  scanf("%d",&c);
	  switch(c)
	  {
	    case 1:start=insert_beg(start);break;
		case 2:start=insert_end(start);break;
		case 3:start=delete_beg(start);break;
		case 4:start=delete_end(start);break;
		case 5:display(start);break;
		case 6:exit(0);
	  }
   }
}

void display(node * start)
{
   node * ptr;
   ptr=start;
   if(ptr==NULL)
   {
     printf("Empty List!!");
     return;
   }
   printf("Elements of the list:  \n");
   while(ptr->next!=start)
   {
       printf("%d",ptr->data);
	   ptr=ptr->next;
   }
   printf("%d\t",ptr->data);
}

node * insert_beg(node * start)
{
   node * ptr;
   node *newnode=malloc(sizeof(node));
   printf("Enter data: \n");
   scanf("%d",&newnode->data);
   
   ptr=start;
   if(start==NULL)
   {
      start=newnode;
	  newnode->next=start;
	  return start;
   }
   while(ptr->next!=start)
   {
      ptr=ptr->next;
   }
   ptr->next=newnode;
   newnode->next=start;
   start=newnode;
   
   return start;
}



node * insert_end(node * start)
{
   node * ptr;
   node * newnode=malloc(sizeof(node));
   printf("Enter data: \n");
   scanf("%d",&newnode->data);
   
   if(start==NULL)
   {
       start = newnode;
	   newnode->next=start;
   }
   else
   {
       ptr=start;
	   while(ptr->next!=start)
	   {
	      ptr=ptr->next;
	   }
	   ptr->next=newnode;   
   }
   newnode->next=start;
   return start; 
}

node * delete_beg(node * start)
{
   node * ptr;
   if(start==NULL)
      printf("List Empty!!");
   else
   {
      ptr=start;
	  while(ptr->next!=start)
	  {
	      ptr=ptr->next;
	  }
	  if(ptr==start)
	  {
	      start=NULL;
	  }
	  else
	  {
	      ptr->next=start->next;
		  ptr=start;
		  start=start->next;
	  }
	  free(ptr);
   
   }
   return start;  
}

node * delete_end(node * start)
{
    node *ptr1,*ptr2;
	
	if(start==NULL)
	{
	   printf("ListEmpty!!");
	}
	else
	{
	    ptr1=start;
		while(ptr1->next!=start)
		{
		    ptr2=ptr1;
			ptr1=ptr1->next;
		}
		if(ptr1==start)
		{
		    start=NULL;
		}
		else
		{
		    ptr2->next=start;
		}
		free(ptr1);
	}
	return start;	 
}


