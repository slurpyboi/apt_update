#include<stdio.h>
void towerofhanoi(int n, char source,char dest,char temp )
    {
            if(n==1)
                {
                        printf("\n Move disk 1 from %c to %c",source,dest);
                        return;
                }
            towerofhanoi(n-1,source,temp,dest);
            printf("\n Moce disk %d from %c to %c",n,source,dest);
            towerofhanoi(n-1,temp,dest,source);
    }
    void main()
    {
            int n;
            printf("Enter the no of disks\n");
            scanf("%d",&n);
            towerofhanoi(n,'A','B','C');
    }