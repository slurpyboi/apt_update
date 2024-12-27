#include<stdio.h>
#include<stdlib.h>

struct node{
     char usn[10];
     char name[10];
     char branch[10];
     int sem;
     char pno[10];    
     struct node * next;
};
struct node * first=NULL;
struct node *temp,*p,*q;
void  nodecreate(){
        temp=(struct node*)malloc(sizeof(struct node));
        printf("\n EnterUSN:");
        scanf("%s", temp->usn);
        printf("\nEnter Name:");
        scanf("%s",temp->name);
        printf("\nEnter Branch:");
        scanf("%s",temp->branch);
        printf("\nEnter Semester:");
        scanf("%d",&temp->sem);
        printf("\nEnter phone number:");
        scanf("%s",temp->pno);
        temp->next=NULL;
}
void insertfront(){
    nodecreate();
    if(first==NULL)
          first=temp;
    else{
        temp->next=first;
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
        q->next=temp;
      }
}
void deletefront(){
    if(first==NULL)
              printf("EMPTY LIST \n");
    else{
            q=first;
            first=first->next;
           printf("\n Student deleted is %s ",q->usn);
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
                printf("\n Student deleted is %s",q->usn);
                free(q); 
   }
}
void display(){
        if(first==NULL)
               printf("\n LIST IS EMPTY \n");
        else{
            printf("\n -------------STUDENT DETAILS----------------\n");
             for(q=first; q!=NULL;q=q->next)
                      printf("%s\t%s\t%s\t%d\t%s------->",q->usn,q->name,q->branch,q->sem,q->pno);
        }
}
int main(){
        int  choice,n,i;
        while(1)
        {
            printf("\n\n-----SINGLY LINKED LIST MENU \n");
            printf("1: CREATE\n 2: DISPLAY\n 3: INSERT AT END\n 4: INSERT AT FRONT\n 5: DELETE AT END\n 6: DELETE FROM FRONT\n 7: EXIT\n Enter your choice\n");
            scanf("%d",&choice);
            switch(choice)
           {
                    case 1:printf("Enter number of students:\n"); scanf("%d",&n);
                            for(i=1;i<=n;i++)
                                insertfront();
                            printf("\n LIST CREATED\n"); break;
                    case 2:  display();  break;        
                    case 3:insertend();  break;         
                    case 4:insertfront();    break;        
                    case 5: deleteend();break;        
                    case 6: deletefront();break;
                    case 7: exit(0);
                    default:printf("Invalid Choice\n");
           } 
    }               
}
