//SJF cpu scheduling
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
    int p[max],at[max],bt[max],ct[max],wt[max],tat[max],i,j,no,count=0,k,l,temp;
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
        tat[i]=0;
        wt[i]=0;
        ct[i]=0;
    }
    for(i=0;i<no-1;i++)
    {
        for(j=0;j<no-i-1;j++)
        {
            if(at[j]>at[j+1] || at[j]==at[j+1] && bt[j]>bt[j+1])
            {
                swap(&p[j+1],&p[j]);
                swap(&at[j+1],&at[j]);
                swap(&bt[j+1],&bt[j]);
            }
        }
    }
    printf("Process no\tArival time\tBurst time\tWaiting time\tturnaroun time\tcompletion time\n");

    ct[0]=at[0]+bt[0];
    for(i=1;i<no;i++)
    {
        for(j=i;j<no;j++)
        {
            if(at[j]<=ct[i-1])
                count++;
        }
        if(count==0)
        {
            temp=at[i]-ct[i-1];
            ct[i]=ct[i-1]+temp+bt[i];
        }
        else
        {
            for(k=i;k<i+count;k++)
            {
                for(l=i;l<i+count;l++)
                {
                    if(bt[l]>bt[l+1])
                    {
                        swap(&p[l+1],&p[l]);
                        swap(&at[l+1],&at[l]);
                        swap(&bt[l+1],&bt[l]);
                    }
                }
            }
            count=0;
            ct[i]=ct[i-1]+bt[i];
        }
    }
    for(i=0;i<no;i++)
    {
        tat[i]=ct[i]-at[i];
        wt[i]=tat[i]-bt[i];
        awt=awt+wt[i];
        atat=atat+tat[i];
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",p[i],at[i],bt[i],wt[i],tat[i],ct[i]);
    }
    atat=atat/no;
    awt=awt/no;
    printf("Average waiting time %f \nAverage turnaround time %f \n",awt,atat);

}