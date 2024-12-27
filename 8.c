#include<stdio.h>
#include<stdlib.h>

struct node
{
    char ssn[20]; //ssn instead usn
    char name[20];
    char dept[20];
    char desig[20];
    int sal;
    char pno[12];
    struct node *next;
    struct node *prev; //extra
};
struct node *first=NULL;
struct node *temp,*q,*p;
void nodecreate(){
    temp=(struct node *)malloc(sizeof(struct node));
    printf("Enter SSN: ");
    scanf("%s",temp->ssn);
    printf("Enter Name: ");
    scanf("%s",temp->name);
    printf("Enter Department: ");
    scanf("%s",temp->dept);
    printf("Enter Designation: ");
    scanf("%s",temp->desig);
    printf("Enter Salary: ");
    scanf("%ld",&temp->sal);
    printf("Enter phone number: ");
    scanf("%s",temp->pno);
    temp->next=NULL;
    temp->prev=NULL; //extra
}
void insertfront(){  
    nodecreate();
    if(first==NULL)
        first=temp;
    else {
        temp->next=first; //extra
        first->prev=temp;
        first=temp;
    }
}
void insertend(){
   nodecreate();
    if(first==NULL)
        first=temp;
    else
    {
        q=first;
        while(q->next!=NULL)
                q=q->next;
        temp->prev=q;//extra
        q->next=temp;
    }
}
void deletefront(){
    if(first==NULL)
       printf("The DLL list is empty. \n");
    else {
       //extra
       q=first;
       printf("Deleted Employee SSN is %s \n\n",q->ssn); //reciprocal
       first=first->next;
       first->prev=NULL; //extra
       free(q);
    }
}
void deleteend(){
    if(first==NULL)
             printf("THE LIST IS EMPTY. \n");
    else  {
            p=q;
            q=first;
            while(q->next!=NULL)
                {
                        p=q;
                        q=q->next;
                }
                p->next=NULL;
                printf("\n Student deleted is %s",q->ssn);
                free(q); 
   }
}


void display()
{
    int count=0;
    if(first==NULL)
       printf(" DLL List is empty. \n");
    else
    {
        printf("The Employee details are:\n");
       for(q=first;q!=NULL;q=q->next)
       {
             printf("%s\t\t%s\t\t%s\t\t%s\t%d\t%s<=======>\n",q->ssn,q->name,q->dept,q->desig, q->sal,q->pno);
            count++;
         }
    }
    printf("\nTotal Number of Employee in the DLL List are: %d\n",count);
}



void main( )
{
    int choice,n,i;
    while(1)
    {
        printf("\n-----DOUBLY LINKED LIST MENU	\n");
        printf("1:CREATE DLL\n");
        printf("2:DISPLAY DLL\n");
        printf("DOUBLE ENDED QUEUE DEMOSTRATION \n");
        printf("3:INSERT AT END OF DLL\n");
        printf("4:DELETE FROM END OF DLL\n");
        printf("5:INSERT AT FRONT OF DLL\n");
        printf("6:DELETE FROM FRONT OF DLL\n");
        printf("7:EXIT\n");
        printf("Enter your choice\n");
        scanf("%d",&choice);
       switch(choice)
       {
            case 1:printf("Enter number of Employees:\n ");
                   scanf("%d",&n);
                   for(i=1;i<=n;i++)
                   {
                       printf("Employee %d details\n",i);
                       insertend();
                   }
                    break;
            case 2: display();
                         break;
            case 3: insertend();
                         break;
            case 4: deleteend();
                         break;
            case 5: insertfront();
                          break;
            case 6: deletefront();
                         break;
            case 7: exit(0);
            default:printf("Invalid Choice\n");
     }
  }
}
