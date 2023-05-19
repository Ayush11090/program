#include<stdio.h>

int main(){
    int process ;
    int ArriveTime[10],BurstTime[10],TurnaroundT[10],WaitingTime[10],FinishTime[10];
    printf("Enter number of process: ");
    scanf("%d",&process);
    int t= 0;
    for (int i = 0; i < process; i++)
    {
        printf("Enter number of Arrival time: ");
        scanf("%d",&ArriveTime[i]);
    }
    for (int i = 0; i < process; i++)
    {
        printf("Enter number of Burst time: ");
        scanf("%d",&BurstTime[i]);
    }
    for (int i = 0; i < process; i++)
    {
       FinishTime[i] = 0; 
    }
    for (int i = 0; i < process; i++)
    {
       FinishTime[i] =t +BurstTime[i]; 
       t = FinishTime[i];
    }
    for (int i = 0; i < process; i++)
    {
       TurnaroundT[i] =FinishTime[i]-ArriveTime[i]; 
    }
    for (int i = 0; i < process; i++)
    {
       WaitingTime[i] =TurnaroundT[i]-BurstTime[i]; 
    }

    printf("Process id\tArrival Time\tBurstTime\tFinishTime\tTurnaroundTime\tWaitingTime\n");

    for (int i = 0; i < process; i++)
    {
        printf("P%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t\n",i,ArriveTime[i],BurstTime[i],FinishTime[i],TurnaroundT[i],WaitingTime[i]);
    }
    
    
  return 0;
    
}