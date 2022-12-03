#include <stdio.h>
#define max 50
int main()
{
    int i, j, n, bt[max],wt[max],tat[max],at[max],ct[max],temp,p[max];
    float awt=0,atat=0;    
    printf("\nEnter the no of process : ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        p[i]=i+1;
    }
    printf("\nEnter burst time of process : ");
   
    for(i=0;i<n;i++)
        scanf("%d",&bt[i]);
    printf("\nEnter arrival time of process : ");
    for(i=0;i<n;i++)
        scanf("%d",&at[i]);
    temp=0;

    //sorting
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(at[j]>at[j+1])
            {
                temp=p[j+1];
                p[j+1]=p[j];
                p[j]=temp;
                temp=at[j+1];
                at[j+1]=at[j];
                at[j]=temp;
                temp=bt[j+1];
                bt[j+1]=bt[j];
                bt[j]=temp;
            }
        }
    }

    printf("Process \t Burst time \t Arrival time \t Completion time \t Waiting time \t Turn Around time \n");
    for(i=0;i<n;i++)
    {
        
        if(i==0){
            ct[0]=at[0]+bt[0];
        }
        else if(at[i]>ct[i-1]){
            temp=at[i]-ct[i-1];
            ct[i]=ct[i-1]+bt[i]+temp;
        }
        else{
            ct[i]=ct[i-1]+bt[i];
        }
        tat[i]=ct[i]-at[i];
        atat=atat + tat[i];
        wt[i]=tat[i]-bt[i];
        awt=awt + wt[i];
        printf("p[%d] \t\t %d \t\t %d \t\t %d \t\t\t %d \t\t %d \n",p[i] ,bt[i], at[i],ct[i],wt[i],tat[i]);
    }
    awt=awt/n;
    atat=atat/n;
    printf("Average waiting time %f \nAverage turnaround time %f \n",awt,atat);
    return 0;
}