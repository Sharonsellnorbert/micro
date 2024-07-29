#include<stdio.h>
void main(){
int ch=0;
while(ch!=5){
printf("1.FCFS 2.SJF 3.Priority 4.Round Robin 5.Exit\n");
printf("Enter the Choice\n");
scanf("%d",&ch);
if(ch==1){
int n;
printf("Enter the limit\n");
scanf("%d",&n);
int p[20],wt[20],tat[20],bt[20],tot_tat=0,tot_wt=0,temp;
printf("Enter the process and burst time\n");
for(int i=0;i<n;i++){
scanf("%d",&p[i]);
scanf("%d",&bt[i]);
}
wt[0]=0,tat[0]=bt[0];
for(int i=1;i<n;i++){
wt[i]=wt[i-1]+bt[i-1];
tat[i]=tat[i-1]+bt[i];
}
for(int i=0;i<n;i++){
tot_tat=tot_tat+tat[i];
tot_wt=tot_wt+wt[i];
}
printf("PROCESS\tBURST TIME\tWAITING TIME\tTURN AROUND TIME\n");
for(int i=0;i<n;i++){
printf("p[%d]\t%d\t\t%d\t\t%d",p[i],bt[i],wt[i],tat[i]);
printf("\n");
}
printf("GANT CHART\n");
for(int i=0;i<n;i++){
printf("\tp[%d]\t",p[i]);
}
printf("\n");
for(int i=0;i<n;i++){
printf("%d\t\t",wt[i]);
}
printf("%d\n",tat[n-1]);
printf("Total Waiting Time is %d\n",tot_wt);
printf("Total Turn Around Time is %d\n",tot_tat);
printf("Average Waiting Time is %f\n",(float)tot_wt/(float)n);
printf("Average Turn Around Time is %f\n\n",(float)tot_tat/(float)n);
}
else if(ch==2){
int n;
printf("Enter the limit\n");
scanf("%d",&n);
int p[20],wt[20],tat[20],bt[20],tot_tat=0,tot_wt=0,temp;
printf("Enter the process and burst time\n");
for(int i=0;i<n;i++){
scanf("%d",&p[i]);
scanf("%d",&bt[i]);
}
for(int i=0;i<n;i++){
for(int j=i+1;j<n;j++){
if(bt[i]>bt[j]){
temp=p[i];
p[i]=p[j];
p[j]=temp;
temp=bt[i];
bt[i]=bt[j];
bt[j]=temp;
}
}
}
wt[0]=0,tat[0]=bt[0];
for(int i=1;i<n;i++){
wt[i]=wt[i-1]+bt[i-1];
tat[i]=tat[i-1]+bt[i];
}
for(int i=0;i<n;i++){
tot_tat=tot_tat+tat[i];
tot_wt=tot_wt+wt[i];
}
printf("PROCESS\tBURST TIME\tWAITING TIME\tTURN AROUND TIME\n");
for(int i=0;i<n;i++){
printf("p[%d]\t%d\t\t%d\t\t%d",p[i],bt[i],wt[i],tat[i]);
printf("\n");
}
printf("GANT CHART\n");
for(int i=0;i<n;i++){
printf("\tp[%d]\t",p[i]);
}
printf("\n");
for(int i=0;i<n;i++){
printf("%d\t\t",wt[i]);
}
printf("%d\n",tat[n-1]);
printf("Total Waiting Time is %d\n",tot_wt);
printf("Total Turn Around Time is %d\n",tot_tat);
printf("Average Waiting Time is %f\n",(float)tot_wt/(float)n);
printf("Average Turn Around Time is %f\n\n",(float)tot_tat/(float)n);
}
else if(ch==3){
int n;
printf("Enter the limit\n");
scanf("%d",&n);
int p[20],wt[20],pr[20],tat[20],bt[20],tot_tat=0,tot_wt=0,temp;
printf("Enter the process and burst time and priority\n");
for(int i=0;i<n;i++){
scanf("%d",&p[i]);
scanf("%d",&bt[i]);
scanf("%d",&pr[i]);
}
for(int i=0;i<n;i++){
for(int j=i+1;j<n;j++){
if(pr[i]>pr[j]){
temp=p[i];
p[i]=p[j];
p[j]=temp;
temp=bt[i];
bt[i]=bt[j];
bt[j]=temp;
temp=pr[i];
pr[i]=pr[j];
pr[j]=temp;
}
}
}
wt[0]=0,tat[0]=bt[0];
for(int i=1;i<n;i++){
wt[i]=wt[i-1]+bt[i-1];
tat[i]=tat[i-1]+bt[i];
}
for(int i=0;i<n;i++){
tot_tat=tot_tat+tat[i];
tot_wt=tot_wt+wt[i];
}
printf("PROCESS\tBURST TIME\tPRIORITY\tWAITING TIME\tTURN AROUND TIME\n");
for(int i=0;i<n;i++){
printf("p[%d]\t%d\t\t%d\t\t%d\t\t%d",p[i],bt[i],pr[i],wt[i],tat[i]);
printf("\n");
}
printf("GANT CHART\n");
for(int i=0;i<n;i++){
printf("\tp[%d]\t",p[i]);
}
printf("\n");
for(int i=0;i<n;i++){
printf("%d\t\t",wt[i]);
}
printf("%d\n",tat[n-1]);
printf("Total Waiting Time is %d\n",tot_wt);
printf("Total Turn Around Time is %d\n",tot_tat);
printf("Average Waiting Time is %f\n",(float)tot_wt/(float)n);
printf("Average Turn Around Time is %f\n\n",(float)tot_tat/(float)n);
}
else if(ch==4){
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
printf("Average Turn Around Time is %f\n\n",(float)tot_tat/(float)n);
}
else{
printf("Wrong Choice");
}
}
}

