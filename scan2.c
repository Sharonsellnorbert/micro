#include <stdio.h>
#include <stdlib.h>
void main()
{
   int maxRange,queue[25],n,head,seektime=0,distance;
   printf("\nEnter maximum range of disk :  ");
   scanf("%d",&maxRange);
   printf("\nEnter initial head position : ");
   scanf("%d",&head);
   printf("\nEnter number of requests : ");
   scanf("%d",&n);
   printf("Enter the requests\n");
   for(int i=0;i<n;i++)
    scanf("%d",&queue[i]);
   queue[n]=maxRange;
   for(int i=0;i<=n;i++){
    for(int j=i+1;j<=n;j++){
        if(queue[i]>queue[j]){
            int temp = queue[i];
            queue[i]=queue[j];
            queue[j]=temp;
        }
    }
   }
   for(int i=0;i<n;i++){
    distance=abs(queue[i+1]-queue[i]);
    seektime+=distance;
    printf("Head movement from %d to %d is %d\n",queue[i],queue[i+1],distance);
   }
   printf("Seektime is %d\n",seektime);
   printf("Avg seektime is %d\n",seektime/n);
}
