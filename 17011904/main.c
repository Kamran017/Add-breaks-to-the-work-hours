#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 100
int main()
{
    int i,j,c,k,sum,listLength,flag,arr[MAX_SIZE],maximumHour,brk=-1,count=0;
    printf("Please enter the length of duration list!\n");
    scanf("%d",&listLength);
    for(i=0;i<listLength;i++){
        printf("Please enter the %d.  duration value ",i+1);
        scanf("%d",&arr[i]);
    };
    printf("Please enter the maximum hour for working!\n");
    scanf("%d",&maximumHour);
    i=0;//i will use this variable as a position for adding breaks.That's why i need to reset this variable
    flag=listLength;
    listLength=listLength+maximumHour/2;//expand the size of array
    for(c=0;c<flag;c++){
      sum=0;
      while(sum<=maximumHour){
        sum=sum+arr[i];
        i++;
        if(sum>maximumHour){
            sum=sum-arr[i-1];
            break;
        };
      };
      //slipping the elements of array
      for (j = listLength-1; j >= i-1; j--){
       arr[j+1] = arr[j];
      };
      arr[i-1] = brk;//add breaks
    }
    for (k = 0; k <listLength; k++)//print matrix with breaks
        printf(" %d ", arr[k]);
    return 0;
}
