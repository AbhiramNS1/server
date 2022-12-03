//Round robin cpu scheduling
#include<stdio.h>
#define max 100
void swap(int *x, int *y)
{
    int temp=*x;
    *x=*y;
    *y=temp;
}
void main()
{
    int at[max],bt[max],ct[max],tat[max],wt[max],p[max],no,i,j,tq,bal[max],temp;
    float awt=0,atat=0;
    printf("Enter number of process:");
    scanf("%d",&no);
    for(i=0;i<no;i++)
    {
        printf("Enter the detail of process %d\n",i+1);
        p[i]=i+1;
        printf("Arival time:");
        scanf("%d",&at[i]);
        printf("Burst time:");
        scanf("%d",&bt[i]);
        bal[i]=bt[i];
        tat[i]=0;
        wt[i]=0;
    }
    printf("Enter time quantum:");
    scanf("%d",&tq);
    //sorting
    for(i=0;i<no-1;i++)
    {
        for(j=0;j<no-i-1;j++)
        {
            if(at[j]>at[j+1])
            {
                swap(&p[j+1],&p[j]);
                swap(&at[j+1],&at[j]);
                swap(&bt[j+1],&bt[j]);
                swap(&bal[j+1],&bal[j]);
            }
        }
    }
    for(i=0;i<no;i++)
        ct[i]=at[0];
    //Round robin 
    int count=no;
    for(i=0;count!=0;i++)
    {
        if(bal[i]==0)
            continue;
        if(bal[i]>tq)
        {
            for(j=0;j<no;j++)
            {
                if(bal[j]==0)
                    continue;
                ct[j]=ct[j]+tq;
            }
            bal[i]=bal[i]-tq;
        }
        else
        {
            for(j=0;j<no;j++)
            {
                if(bal[j]==0)
                    continue;
                ct[j]=ct[j]+bal[i];
            }
            wt[i]=ct[i]-bal[i]-at[i];
            bal[i]=0;
            count--;
        }
        if(i==no-1)
            i=-1;
    }
    printf("Process\tArrival time\tBurst time\tCompletion time\t\tWaiting time\tTurn Around time\n");
    for(i=0;i<no;i++)
    {
        tat[i]=ct[i]-at[i];
        atat=atat+tat[i];
        awt=awt+wt[i];
        printf("p[%d]\t%d\t\t%d\t\t%d\t\t\t%d\t\t%d\n",p[i] ,at[i], bt[i],ct[i],wt[i],tat[i]);
    }
    awt=awt/no;
    atat=atat/no;
    printf("Average waiting time %f \nAverage turnaround time %f \n",awt,atat);
}