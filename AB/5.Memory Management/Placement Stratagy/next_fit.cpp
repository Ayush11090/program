#include <bits/stdc++.h>
using namespace std;

void NextFit(int blockSize[], int m, int processSize[], int n)
{
    int allocation[n], j = 0, t = m - 1;

    memset(allocation, -1, sizeof(allocation));

    for (int i = 0; i < n; i++)
    {
        while (j < m)
        {
            if (blockSize[j] >= processSize[i])
            {
                allocation[i] = j;

                blockSize[j] -= processSize[i];

                t = (j - 1) % m;
                break;
            }
            if (t == j)
            {
                t = (j - 1) % m;
                break;
            }
            j = (j + 1) % m;
        }
    }

    cout << "\nProcess No.\tProcess Size\tBlock no.\n";
    for (int i = 0; i < n; i++)
    {
        cout << " " << i + 1 << "\t\t" << processSize[i] << "\t\t";
        if (allocation[i] != -1)
            cout << allocation[i] + 1;
        else
            cout << "Not Allocated";
        cout << endl;
    }
}

// Driver program
int main()
{
    // int m;
    // cout << "Enter the no. of memory blocks" << endl;
    // cin >> m;
    // int blockSize[m];
    // for (int i = 0; i < m; i++)
    // {
    //     cout << "Enter the size of memory blocks" << endl;
    //     cin >> blockSize[i];
    // }
    // int n;
    // cout << "Enter the no. of processes" << endl;
    // cin >> n;
    // int processSize[n];
    // for (int i = 0; i < n; i++)
    // {
    //     cout << "Enter the process size" << endl;
    //     cin >> processSize[i];
    // }

    int blockSize[] = { 5, 10, 20 };
    int processSize[] = { 10, 20, 5 };
    int m = sizeof(blockSize) / sizeof(blockSize[0]);
    int n = sizeof(processSize) / sizeof(processSize[0]);
    NextFit(blockSize, m, processSize, n);
    return 0;
}
