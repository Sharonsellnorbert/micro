#include<stdio.h>
void main(){
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
printf("Average Turn Around Time is %f\n",(float)tot_tat/(float)n);
}


