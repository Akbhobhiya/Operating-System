#include <stdio.h> 
#include <unistd.h> 
#include <sys/wait.h> 
#include <sys/types.h> 
#include <string.h> 
#include <stdlib.h> 
  
int main(int argc , char *argv[] ) 
{ 
    pid_t pid; 
  
    if (argc != 2) 
    { 
        printf("Argument is missing!!\n"); 
        exit(0); 
    } 
  
    if (atoi(argv[1])<0) 
    { 
        printf("Negative number entered! %d", atoi(argv[1])); 
        exit(0); 
    } 
  
    pid=fork(); 
  
    if ( pid<0 ) 
    { 
        printf("Failed to create child!!\n"); 
        exit(0); 
    } 
  
    else if ( pid==0 ) 
    {  
        int i, j, k = 2, n; 
        n = atoi(argv[1]); 
        int arr[n];
        arr[0] = 1; 
        for(i=1;i<n;i++) 
        { 
            arr[i] = arr[i-1]*k; 
            k++; 
        } 
        printf(" The factorial is : %d ",arr[i-1]);
    } 
    else
    { 
        wait(NULL); 
        printf("\nDone\n"); 
    } 
} 
