#include<stdio.h>
#include<stdlib.h>
void main(){
int head,req[10],tot_mov,np,dis,a[10],seektime=0;
printf("Enter the total number of requests\n");
scanf("%d",&np); 
printf("Enter the request array\n");
for(int i=1;i<=np;i++){
scanf("%d",&req[i]);
}
printf("Enter the head\n");
scanf("%d",&head);
req[0]=head;
for(int i=0;i<np;i++){
dis=abs(req[i]-req[i+1]);
seektime+=dis;
printf("seek time from %d to %d is %d\n",req[i],req[i+1],dis);
}
printf("Total Head movement is %d",seektime);
}



