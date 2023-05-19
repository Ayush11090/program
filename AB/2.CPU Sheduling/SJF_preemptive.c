#include<stdio.h>

int main(){
    int process ;
    int ArriveTime[10],BurstTime[10],TurnaroundT[10],WaitingTime[10],FinishTime[10],Priority[10],Time[10];
    printf("Enter number of process: ");
    scanf("%d",&process);
    int t= 0,count= 0;
    int time,end;
    for (int i = 0; i < process; i++)
    {
        printf("Enter Arrival time: ");
        scanf("%d",&ArriveTime[i]);
    }
    for (int i = 0; i < process; i++)
    {
        printf("Enter Burst time: ");
        scanf("%d",&BurstTime[i]);
    }
    for (int i = 0; i < process; i++)
    {
        printf("Enter priority: ");
        scanf("%d",&Priority[i]);
    }
    for (int i = 0; i < process; i++)
    {
       FinishTime[i] = 0; 
    }
    for (int i = 0; i < process; i++)
    {
        Time[i] = BurstTime[i];
    }
    int min = 9;
    BurstTime[min] = 999;
    for(time=0; count!=process; time++)
    {
        min=9;
        for(int i=0; i<process; i++)
        {
            if(ArriveTime[i]<=time && BurstTime[i]<=BurstTime[min] && BurstTime[i]>0 )
                min=i;
        }
        BurstTime[min]--;

        if(BurstTime[min]==0)
        {
            count++;
            end=time+1;
            FinishTime[min] = end;
            WaitingTime[min] = end - ArriveTime[min] - Time[min];
            TurnaroundT[min] = end - ArriveTime[min];
        }
    }
    

    printf("Process id\tArrival Time\tBurstTime\tPriority\tFinishTime\tTurnaroundTime\tWaitingTime\n");

    for (int i = 0; i < process; i++)
    {
        printf("P%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t\n",i,ArriveTime[i],Time[i],Priority[i],FinishTime[i],TurnaroundT[i],WaitingTime[i]);
    }
    
    
  return 0;
    
}