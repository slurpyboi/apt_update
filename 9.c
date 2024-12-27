#include <stdio.h>
#include <stdlib.h>
#include<math.h>

struct node 
{
        int coef;
        int x,y,z;
        struct node* next;
};

struct node *temp, *q; 
struct node * poly,*p1,*p2,*ps ;
int px,py,pz,cf;

struct node *insert(struct node *head ,int cf, int px,int py, int pz)
{
    temp = (struct node*) malloc(sizeof(struct node));
    temp->coef = cf;
    temp->x = px;
    temp->y=py;
    temp->z=pz;
    temp->next = NULL;
          if (head == NULL)
                 head = temp;
         else
          {
        q=head;
        while (q->next != NULL) 
                     q = q->next;
        q->next = temp;
         }
     return head;
}


     
struct node*  readpoly(struct node *head)
{
    int px,py,pz,cf;
    int n,i;
    printf("\nEnter the no of terms in polynomial ");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        printf("\nEnter coeff: ");
        scanf("%d",&cf);
        printf("\nEnter x, y, z powers: ");
        scanf("%d%d%d", &px, &py, &pz);
        head=insert(head,cf,px,py,pz);
       
    }
    return head;
}
  
  

void print(struct node* head) 
{
     
    for(q=head;q!=NULL; q=q->next)
                printf("%dx^%dy^%dz^%d+ ", q->coef, q->x,q->y,q->z);
}
       



void evaluate(struct node *head)
{
    int result=0;

    printf("\nEnter values of x, y, z");
    scanf("%d%d%d", &px, &py, &pz);
    for(q=head;q!=NULL;q=q->next)
                     result = result + (q->coef * pow(px,q->x) * pow(py,q->y) * pow(pz,q->z));
           
      printf("\nPolynomial result is: %d", result);
}




struct node* add(struct node* p1, struct node* p2)
{
    struct node* ps = NULL;
   
   while ((p1 != NULL) &&  (p2 != NULL))
    {
   if((p1->x == p2->x) && (p1->y == p2->y) &&(p1->z ==p1->z))
   {
        ps=insert(ps, p1->coef+p2->coef,p1->x,p1->y,p1->z);
        p1 = p1->next;
        p2 = p2->next;
    } 
   else if (p1->x > p2->x) 
   {
         ps=insert(ps, p1->coef, p1->x,p1->y,p1->z);
         p1 = p1->next;
    }
                else 
    {
                      ps=insert(ps, p2->coef, p2->x,p2->y,p2->z);
        p2 = p2->next;
     }
    }
    
    while (p1 != NULL)
    {
        ps=insert(ps, p1->coef, p1->x,p1->y,p1->z);
        p1 = p1->next;
      }
   while (p2 != NULL)
    {
            ps=insert(ps, p2->coef, p2->x,p2->y,p2->z);
            p2 = p2->next;
    }
    
        return ps;
}



void  main()
{
     int choice;
     struct node *head=NULL;
     while (1)
     {
         printf("\n\n1.Read Polynomial ");
         printf("\n2. Print Polynomial");
         printf("\n3. Polynomial Evaluation");
         printf("\n4. Polynomial Additon ");
         printf("\n5.Exit");
         printf("\n Enter your choice");
         scanf("%d",&choice);
         
          switch(choice)
         {
             case 1:printf("\nRead a Polynomial");
                          head=readpoly(head);
                          break;

              case 2: printf("\nPolynomial is\n");
                           print(head);
                           break;

            case 3: evaluate(head);
                          break;

            case 4: printf("\nEnter polynomial 1 ");
                           p1=readpoly(p1);
                           printf("\nEnter polynomaiial 2");
                           p2=readpoly(p2);
                           printf("\n Polynomial 1\n");
                          print(p1);
                    ps=add(p1,p2);
                    printf("\n Polynomial 2\n");
                    print(p2);
                    printf("\n Polynomial Adddition Result\n ");
                    print(ps);
                    break;

            case 5: exit(0);

           default:printf("Invalid choice");
       }         
           }
}
