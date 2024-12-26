#include<stdio.h> 
#include<string.h> 
 
 
char str[50], pat[50], rep[50], ans[50]; 
int i, j, m, k, flag=0; 
 
void stringmatch() 
 
{ 
       i = m = j = 0; 
       while(str[m]!= '\0') 
    { 
                 if(str[m]==pat[i]) // ...... matching 
                { 
                    i++; m++; 
                     if(pat[i] == '\0') //.....found occurrences. 
                 { 
                           flag = 1;
                            for(k = 0; rep[k] !='\0'; k++ , j++) 
                                         ans[j] = rep[k]; 
                                    i = 0; 
                   
                } 
              } 
        else  
            
                 ans[j++] = str[m++]; 
                   
       }    //while end 
 
    ans[j] = '\0'; 
}  
 
 
void main() 
{ 
 
        printf("\nEnter a main string \n"); 
        gets(str); 
        printf("\nEnter a pattern string \n"); 
        gets(pat); 
        printf("\nEnter a replace string \n"); 
        gets(rep); 
        stringmatch(); 
        if(flag == 1) 
                printf("\nThe resultant string is\n %s" , ans); 
        else 
                printf("\nPattern string NOT found\n"); 
}