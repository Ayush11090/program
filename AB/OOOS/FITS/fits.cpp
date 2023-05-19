#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> firstfit(vector<int> block, int n, vector<int> process, int m)
{
    vector<int> ans(m, -1);
    vector<int> internalfrag(m, 0);
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (block[j] >= process[i])
            {
                ans[i] = j;
                block[j] -= process[i];
                break;
                
            }
        }
    }
    
    return ans;
}
void bestfit(vector<int> block, int n, vector<int> process, int m)
{
    vector<int> ans(m, -1);
    vector<int> internalfrag(m, 0);
    int k = 0;
    for (int i = 0; i < n; i++)
    {
        int minidx = -1;
        vector<int> diff;
        for (int j = 0; j < m; j++)
        {
            diff.push_back(block[i] - process[j]);
        }
        for (int j = 0; j < diff.size(); j++)
        {
            if (diff[j] >= 0)
            {
                if (minidx == -1 || diff[j] < diff[minidx])
                {
                    minidx = j;
                }
            }
        }
        if (minidx != -1)
        {
            ans[minidx] = i;
            block[i] -= process[minidx];
            internalfrag[i] = block[i];
            cout << "Process " << k + 1 << " is allocated to  " << minidx + 1 << "th block" << endl;
        }
        else
        {
            cout << "Process " << k + 1 << " is not allocaatee" << endl;
        }
        k++;
    }
    
}

void worstfit(vector<int> block, int n, vector<int> process, int m)
{
    vector<int> ans(m, -1);
    vector<int> internalfrag(m, 0);
    int k = 0;
    for (int i = 0; i < m; i++)
    {
        int maxidx = -1;
        vector<int> diff(n);
        for (int j = 0; j < n; j++)
        {
            diff[j] = block[j] - process[i];
        }
        for (int j = 0; j < n; j++)
        {
            if (diff[j] >= 0)
            {
                if (maxidx == -1 || diff[j] > diff[maxidx])
                {
                    maxidx = j;
                }
            }
        }
        if (maxidx != -1)
        {
            ans[i] = maxidx;
            block[maxidx] -= process[i];
            internalfrag[i] = block[maxidx];
            cout << "Process " << k + 1 << " is allocated to  " << maxidx + 1 << "th block" << endl;
        }
        else
        {
            cout << "Process " << k + 1 << " is not allocated" << endl;
        }
        k++;
    }
}
void next(vector<int> block, int n, vector<int> process, int m)
{
    vector<int> ans(m, -1);
    vector<int> internalfrag(m, 0);
    int k = 0;
    for (int i = 0; i < m; i++)
    {
        int all = -1;
        for (int j = k; j < n; j++)
        {
            if (block[j] >= process[i])
            {
                cout << "Process No." << i + 1 << " is allocate to Block No." << j + 1 << endl;
                block[j] -= process[i];
                internalfrag[i] = block[j];
                all = 1;
                k = j; // update k to start from the next block
                break;
            }
        }
        if (all == -1)
        {
            cout << "Process No." << i + 1 << " is not allocate " << endl;
        }
    }
}

int main()
{
    vector<int> block{100, 500, 200, 300, 600};
    vector<int> process{212, 417, 112, 426};
    vector<int> ans = firstfit(block, 5, process, 4);
    cout << "Firstfit->" << endl;
    for (int i = 0; i < ans.size(); i++)
    {
        if (ans[i] == -1)
        {
            cout << "Process No. " << i + 1 << " is Not assigned" << endl;
        }
        else
        {
            cout << "Process No. " << i + 1 << " is assigned to block " << ans[i] + 1 << endl;
        }
    }
    cout << "Best Fit->" << endl;
    bestfit(block, 5, process, 4);
    cout << "Worst Fit->" << endl;
    worstfit(block, 5, process, 4);
    cout << "Next Fit->" << endl;
    next(block, 5, process, 4);

    return 0;
}

