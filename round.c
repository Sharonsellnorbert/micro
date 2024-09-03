#include<stdio.h>
void main(){
int n;
printf("Enter the limit\n");
scanf("%d",&n);
int p[20],wt[20],tat[20],bt[20],tot_tat=0,tot_wt=0,temp,q,tot=0,f=0,rev[20],t[20],j=1;
t[0]=0;
printf("Enter the Quantum Number");
scanf("%d",&q);
printf("Enter the process and burst time\n");
for(int i=0;i<n;i++){
scanf("%d",&p[i]);
scanf("%d",&bt[i]);
rev[i]=bt[i];
}
printf("GANT CHART\n");
while(f!=n){
for(int i=0;i<n;i++){
if(rev[i]>q){
tot=tot+q;
rev[i]=rev[i]-q;
printf("\tp[%d]\t",p[i]);
t[j]=tot;
j++;
}
else if(rev[i]==0){
continue;
}
else{
tot=tot+rev[i];
rev[i]=0;
tat[i]=tot;
wt[i]=tot-bt[i];
f++;
printf("\tp[%d]\t",p[i]);
t[j]=tot;
j++;
}
}
}
for(int i=0;i<n;i++){
tot_tat=tot_tat+tat[i];
tot_wt=tot_wt+wt[i];
}
printf("\n");
for(int i=0;i<j;i++){
printf("%d\t\t",t[i]);
}
printf("\n");
printf("PROCESS\tBURST TIME\tWAITING TIME\tTURN AROUND TIME\n");
for(int i=0;i<n;i++){
printf("p[%d]\t%d\t\t%d\t\t%d",p[i],bt[i],wt[i],tat[i]);
printf("\n");
}
printf("\nTotal Waiting Time is %d\n",tot_wt);
printf("Total Turn Around Time is %d\n",tot_tat);
printf("Average Waiting Time is %f\n",(float)tot_wt/(float)n);
printf("Average Turn Around Time is %f\n",(float)tot_tat/(float)n);
}


