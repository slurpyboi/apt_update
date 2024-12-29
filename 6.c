#include<stdio.h> 
#include<stdlib.h> 
#define  maxsize 5 
 
char cq[maxsize]; 
int front,rear; 
 
void insertq(char item)
{ 
     if (front==(rear+1)% maxsize) 
         printf("\n\n  CIRCULAR QUEUE FULL\n"); 
     else 
          { 
          if(front==-1)  
                    front=rear=0; 
          else 
                    rear=(rear+1)%maxsize; 
     
          cq[rear]=item; 
          printf("\nRear=%d Front= %d\n",rear,front); 
          } 
} 
 
void deleteq() 
{ 
     if((front==-1)) 
          printf("\n CIRCULAR QUEUE  EMPTY\n"); 
     else 
          { 
                    printf("\nDELETED  ELEMENT  FROM  QUEUE  IS:%c\n", cq[front]); 
                    cq[front]= '-'; 
                    if(front==rear) 
                         front=rear=-1; 
                    else 
                         front=(front+1)%maxsize; 
                    printf("\nRear = %d Front = %d \n",rear,front); 
          } 
} 
 
void display() 
{ 
    int i; 
    if((front==-1)) 
         printf("QUEUE  EMPTY\n"); 
    else 
    { 
            printf("The  Queue  Elements   are\n"); 
            for(i=0;i<maxsize;i++) 
                        printf("%c \t",cq[i]); 
            printf("\nRear = %d Front = %d \n",rear,front); 
    } 
} 
 
 int main() 
{ 
     int choice; 
     char item ; 
     front=rear=-1; 
     while(1) 
        { 
        printf("\n\n-------QUEUE MENU \n"); 
        printf("\n1.INSERT INTO QUEUE"); 
        printf("\n2.DELETE FROM QUEUE"); 
        printf("\n3.DISPLAY QUEUE"); 
        printf("\n4.EXIT"); 
 
        printf("\n\n  ENTER YOUR CHOICE:");  
        scanf("%d",&choice); 
        switch(choice) 
        { 
             case  1:printf("\nENTER THE QUEUE ELEMENT:");  
                            scanf(" %c",&item); 
                            insertq(item);  
                            break; 
 
             case 2: deleteq(); 
                            break;  
 
             case 3:display(); 
                            break; 
 
             case 4:exit(0); 
 
              default:printf("\nInvalid Choice.\n"); 
      } //switch end 
    }//while end 
    return 0;
}
