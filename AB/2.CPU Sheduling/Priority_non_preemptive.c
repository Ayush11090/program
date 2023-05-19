#include<stdio.h>

int main(){
    int process;
    int ArriveTime[10],BurstTime[10],TurnaroundT[10],WaitingTime[10],FinishTime[10],Priority[10],Time[10];
    printf("Enter number of process: ");
    scanf("%d",&process);
    int t= 0,count= 0;
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
  
    int pos;
  for(int i=0;i<process;i++)
	{
		pos=i;
		for(int j=i+1;j<process;j++)
		{
			if(Priority[j]<Priority[pos])
			{
				pos=j;
			}
		}
		t=Priority[i];
		Priority[i]=Priority[pos];
		Priority[pos]=t; 
		
		t=BurstTime[i];
		BurstTime[i]=BurstTime[pos];
		BurstTime[pos]=t;  
	} 
    for (int i = 0; i < process; i++)
    {
       FinishTime[i] = 0; 
    }
    t =0;
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
    
    printf("Process id\tArrival Time\tBurstTime\tPriority\tFinishTime\tTurnaroundTime\tWaitingTime\n");

    for (int i = 0; i < process; i++)
    {
        printf("P%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t\n",i,ArriveTime[i],BurstTime[i],Priority[i],FinishTime[i],TurnaroundT[i],WaitingTime[i]);
    }
    
    
  return 0;
    
}