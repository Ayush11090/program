#include <bits/stdc++.h>
using namespace std;
int ADDRESSMAP(int C_VA, int arr[], int page_size, int n)
{
    int pte = C_VA / page_size;
    string temp = "";

    if (pte >= n)
    {
        cout << "Page Fault" << endl;
        return -1;
    }
    else
    {
        return ((arr[pte] * page_size) + (C_VA % page_size));
    }
}
int convert(string VA)
{
    int n = VA.length();
    int a = 1;
    int res = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        if (VA[i] == '1')
        {
            res += a * 1;
        }
        a = a * 2;
    }
    return res;
}
int main()
{
    int ptr;
    int page_size;
    string VA;
    int C_VA;
    int arr[100];
    char M[1000][4];
    int VA_SPACE = 100;
    int READ_SPACE = 300;
    cout << "Enter the size of the page: ";
    cin >> page_size;
    cout << endl;
    int n;
    cout << "Enter the number of entries in the page table:" << endl;
    cin >> n;
    cout << "Enter the contents of the page table";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

   

        cout << "Enter binary virtual address: ";
        cin >> VA;
        C_VA = convert(VA);

        cout << "The real address is:" << ADDRESSMAP(C_VA, arr, page_size, n) << endl;
}
