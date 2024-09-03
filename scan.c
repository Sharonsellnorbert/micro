#include<stdio.h>
void main(){
int head,req[10],tot_mov,np,dis,a[10],seektime=0,queue[20],max,dir,temp;
printf("Enter the total number of requests\n");
scanf("%d",&np);
printf("Enter the Max SIZE");
scanf("%d",&max); 
printf("Enter the request array\n");
for(int i=0;i<np;i++){
scanf("%d",&req[i]);
}
printf("Enter the head\n");
scanf("%d",&head);
for(int i=0;i<np;i++){
for(int j=i+1;j<np;j++){
temp=req[i];
req[i]=req[j];
req[j]=temp;
}
printf("Enter the direction 0-low/1-high");
scanf("%d",&dir);
if(dir==0){
distance+=head-req[np];
}
else if(dir==1){
distance=(max-1)-head+((max-1)-req[0]);
}


