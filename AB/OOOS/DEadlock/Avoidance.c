#include <stdio.h>

void bankers()
{
    int n, r, i, j, k;

    printf("\n Enter the number of resources : ");
    scanf("%d", &r);
    printf("\n Enter the number of processes : ");
    scanf("%d", &n);

    int alloc[n][r], max[n][r], avail[r];

    printf("\nEnter allocation matrix:");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < r; j++)
        {
            printf("\nProcess %d (Allocated Resourse %d):", i + 1, j + 1);
            scanf("%d", &alloc[i][j]);
        }
    }

    printf("\nEnter max matrix:");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < r; j++)
        {
            printf("\nProcess %d (Max Resourse %d):", i + 1, j + 1);
            scanf("%d", &max[i][j]);
        }
    }

    printf("\nEnter available resources:\n");
    for (int i = 0; i < r; i++)
    {
        scanf("%d", &avail[i]);
    }

    int f[n], ans[n], ind = 0;
    for (k = 0; k < n; k++)
    {
        f[k] = 0;
    }
    int need[n][r];
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < r; j++)
            need[i][j] = max[i][j] - alloc[i][j];
    }
    int y = 0;
    for (k = 0; k < 5; k++)
    {
        for (i = 0; i < n; i++)
        {
            if (f[i] == 0)
            {

                int flag = 0;
                for (j = 0; j < r; j++)
                {
                    if (need[i][j] > avail[j])
                    {
                        flag = 1;
                        break;
                    }
                }

                if (flag == 0)
                {
                    ans[ind++] = i;
                    for (y = 0; y < r; y++)
                        avail[y] += alloc[i][y];
                    f[i] = 1;
                }
            }
        }
    }

    printf("Th SAFE Sequence is as follows\n");
    for (i = 0; i < n - 1; i++)
        printf(" P%d ->", ans[i]);
    printf(" P%d", ans[n - 1]);
}
int main()
{
    bankers();

    return (0);
}
