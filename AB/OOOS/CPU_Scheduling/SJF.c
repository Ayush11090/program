#include <stdio.h>
#include <stdlib.h>
struct Process
{
    int Proc_id, AT, BT, Priority, FT, TT, WT, RBT;
};
void SJF_P(struct Process pr[], int size)
{
    int current_time = 0, total_WT = 0, total_TT = 0;
    int remaining_Processes = size;
    printf("The Gantt Chart is:\n");
    while (remaining_Processes)
    {
        int shortest_job_index = -1;
        int shortest_job_burst_time = 99999;
        for (int i = 0; i < size; i++)
        {
            if (pr[i].RBT > 0 && pr[i].AT <= current_time)
            {
                if (pr[i].RBT < shortest_job_burst_time)
                {
                    shortest_job_index = i;
                    shortest_job_burst_time = pr[i].RBT;
                }
            }
        }
        if (shortest_job_index == -1)
        {
            current_time++;
            continue;
        }
        pr[shortest_job_index].RBT--;
        current_time++;
        printf("P%d(%d) |", pr[shortest_job_index].Proc_id, current_time);
        if (pr[shortest_job_index].RBT == 0)
        {
            pr[shortest_job_index].TT = current_time - pr[shortest_job_index].AT;
            pr[shortest_job_index].WT = pr[shortest_job_index].TT - pr[shortest_job_index].BT;
            pr[shortest_job_index].FT = pr[shortest_job_index].TT + pr[shortest_job_index].AT;
            remaining_Processes--;
        }
    }
    printf("\n\n");
    printf("Process\tArrTime\tBurstTime Priority FT   TT   WT \n");
    for (int p = 0; p < size; p++)
    {
        printf("%d\t  ", pr[p].Proc_id);
        printf("%d\t  ", pr[p].AT);
        printf("%d\t  ", pr[p].BT);
        printf("  %d\t  ", pr[p].Priority);
        printf(" %d\t", pr[p].FT);
        printf("%d  ", pr[p].TT);
        printf(" %d\t  ", pr[p].WT);
        printf("\n");
    }
    for (int i = 0; i < size; i++)
    {
        total_WT = total_WT + pr[i].WT;
        total_TT = total_TT + pr[i].TT;
    }
    float avg_WT = (float)total_WT / size;
    float avg_TT = (float)total_TT / size;
    printf("\nAverage Waiting Time: %f\n", avg_WT);
    printf("Average TurnAround Time: %f", avg_TT);
}
int main()
{
    int n;
    printf("Enter no of Processes: \n");
    scanf("%d", &n);
    struct Process p[n];
    for (int i = 0; i < n; i++)
    {
        printf("Enter Process number: \n");
        scanf("%d", &p[i].Proc_id);
        printf("Enter AT: \n");
        scanf("%d", &p[i].AT);
        printf("Enter BT: \n");
        scanf("%d", &p[i].BT);
        p[i].RBT = p[i].BT;
        printf("Enter Priority: \n");
        scanf("%d", &p[i].Priority);
    }
    SJF_P(p, n);
    return 0;
}

