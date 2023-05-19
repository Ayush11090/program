#include <stdio.h>

struct Process
{
    int Proc_Id, AT, BT, Priority, FT, TT, WT;
};

void FCFS(struct Process pr[], int size)
{
    int time = 0, total_WT = 0, total_TT = 0;
    for (int k = 0; k < size; k++)
    {
        if (k > 0)
        {
            pr[k].FT = pr[k].BT + pr[k - 1].FT;
        }
        else
        {
            pr[k].FT = pr[k].BT;
        }
        pr[k].TT = pr[k].FT - pr[k].AT;
        pr[k].WT = pr[k].TT - pr[k].BT;
    }

    printf("The Gantt Chart is:\n");
    for (int i = 0; i < size; i++)
    {
        printf("  P%d  ", pr[i].Proc_Id);
    }
    printf("\n");
    printf("%d   ", 0);

    for (int j = 0; j < size; j++)
    {
        time = time + pr[j].BT;
        printf("%d    ", time);
    }
    printf("\n\n");

    printf("Process\tArrTime\tBurstTime Priority FT   TT   WT \n");
    for (int p = 0; p < size; p++)
    {
        printf("%d\t  ", pr[p].Proc_Id);
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
    printf("Average Waiting Time: %f\n", avg_WT);
    printf("Average Turn-Around Time: %f\n", avg_TT);
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
        scanf("%d", &p[i].Proc_Id);
        printf("Enter AT: \n");
        scanf("%d", &p[i].AT);
        printf("Enter BT: \n");
        scanf("%d", &p[i].BT);
        printf("Enter Priority: \n");
        scanf("%d", &p[i].Priority);
    }
    FCFS(p, n);
    return 0;
}
