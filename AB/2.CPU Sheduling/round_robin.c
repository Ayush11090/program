#include<stdio.h>
#define MAX 10

void roundrobin(){
        int n, quantum, i;
    int wt[MAX], tat[MAX], at[MAX], bt[MAX], rt[MAX],ct[MAX],ft[MAX];
    int total_wt = 0, total_tat = 0;


    printf("Enter the number of processes: ");
    scanf("%d", &n);


    printf("Enter the arrival time and burst time for each process:\n");
    for (i = 0; i < n; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d %d", &at[i], &bt[i]);
        rt[i] = bt[i];
    }


    printf("Enter time quantum: ");
    scanf("%d", &quantum);
    int count=0;
    int time=0;
        while (count != n) {
        for (i = 0; i < n; i++) {
            if (rt[i] > 0) {
                if (rt[i] <= quantum) {
                    time += rt[i];
                    ct[i] = time;
                    rt[i] = 0;
                    count++;
                } else {
                    time += quantum;
                    rt[i] -= quantum;
                }
            }
        }
    }


    for (int i = 0; i < n; i++)
    {
       tat[i] = ct[i]-at[i]; 
    }
    for (int i = 0; i < n; i++)
    {
       wt[i] =tat[i]-bt[i]; 
    }
    
   printf("AT\t\tBT\t\tTAT\t\tCT\t\tWT");
    for(int i=0;i<n;i++){
        printf("\n");
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d",at[i],bt[i],tat[i],ct[i],wt[i]);
    }
    


}
int main(){
    roundrobin();
    return 0;
}