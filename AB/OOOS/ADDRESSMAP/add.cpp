#include <iostream>
#include <cmath>

using namespace std;

void addressmap(int VA, int n, int a[], int pagesize)
{
    float d = (float)VA;
    int b = ceil(d / pagesize);
    if (b > n)
    {
        cout << "\n Invalid Page Fault";
    }
    else
    {
        cout << "\nReal Address for " << VA << " is:\n" << a[b - 1] * (pagesize) + (VA % pagesize);
    }
}

int main()
{
    int n;
    cout << "Number of page table entries: ";
    cin >> n;

    float ps;
    cout << "Page size: ";
    cin >> ps;

    int a[n];

    cout << "Enter " << n << " Page table entries: ";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int VA;
    cout << "Enter the Virtual Address: ";
    cin >> VA;

    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }

    addressmap(VA, n, a, ps);

    return 0;
}
