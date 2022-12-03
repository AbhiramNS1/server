//cpu scheduling--priorite(Premetive)--not completed
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
    int p[max],at[max],bt[max],ct[max],prio[max],wt[max],tat[max],i,j,no,x,temp;
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
        printf("Priorite of process:");
        scanf("%d",&prio[i]);
        tat[i]=0;
        wt[i]=0;
        ct[i]=0;
    }
    for(i=0;i<no-1;i++)
    {
        for(j=0;j<no-i-1;j++)
        {
            if(at[j]>at[j+1])
            {
                swap(&p[j+1],&p[j]);
                swap(&at[j+1],&at[j]);
                swap(&bt[j+1],&bt[j]);
                swap(&prio[j+1],&prio[j]);
            }
        }
    }
    for(i=0;i<no-1;i++)
    {
        for(j=0;j<no-i-1;j++)
        {
            if(at[j]==at[j+1])
            {
                if(prio[j]>prio[j+1])
                {
                    swap(&p[j+1],&p[j]);
                    swap(&at[j+1],&at[j]);
                    swap(&bt[j+1],&bt[j]);
                    swap(&prio[j+1],&prio[j]);
                }
            }
        }
    }
    x=at[no-1];
    printf("Process no\tArival time\tBurst time\tPriorite\tWaiting time\tturnaroun time\tcompletion time\n");
    for(i=0;i<no;i++)
    {
        
        printf("%d\t\t%d\t\t%d\t\t%d\n",p[i],at[i],bt[i],prio[i]);
    }
}