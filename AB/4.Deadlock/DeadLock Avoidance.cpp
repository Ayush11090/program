#include<stdio.h>
#include<conio.h>
int max[10][10], need[10][10], allocation[10][10], available[10], flag[10], safe[10], seq[10];
int n, m, i, j, count=0;
void input()
{
    printf("Enter the no of Processes: ");
    scanf("%d", &n);
    printf("Enter the no of Resources: ");
    scanf("%d", &m);
    for(i=0;i<n;i++)
    {
        printf("\nEnter the Allocation for Process %d: ", i+1);
        for(j=0;j<m;j++)
        {
            scanf("%d", &allocation[i][j]);
        }
    }
    for(i=0;i<n;i++)
    {
        printf("\nEnter the Maximum for Process %d: ", i+1);
        for(j=0;j<m;j++)
        {
            scanf("%d", &max[i][j]);
        }
    }
    printf("\nEnter the Available Resources: ");
    for(i=0;i<m;i++)
    {
        scanf("%d", &available[i]);
    }
}
void calculate_need()
{
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }
}
int check(int i)
{
    for(j=0;j<m;j++)
    {
        if(need[i][j]>available[j])
        {
            return 0;
        }
    }
    return 1;
}
void deadlock_avoidance()
{
    calculate_need();
    for(i=0;i<n;i++)
    {
        flag[i]=0;
    }
    for(i=0;i<n;i++)
    {
        if(check(i)==1 && flag[i]==0)
        {
            for(j=0;j<m;j++)
            {
                available[j] += allocation[i][j];
            }
            flag[i]=1;
            seq[count]=i+1;
            count++;
            i=-1;
        }
    }
}
void output()
{
    if(count==n)
    {
        printf("\nSystem is in Safe State.");
        printf("\nSafe Sequence is: ");
        for(i=0;i<n;i++)
        {
            printf("P%d\t", seq[i]);
        }
    }
    else
    {
        printf("\nSystem is in Deadlock State.");
    }
}
int main()
{
    input();
    deadlock_avoidance();
    output();
    return 0;
}
