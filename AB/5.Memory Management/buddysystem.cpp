#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Buddy {
    public:
        class Pair {
            public:
                int lb, ub;
                Pair(int a = 0, int b = 0) : lb(a), ub(b) {}
        };
        int size;
        vector<Pair> arr[100];

        Buddy(int s) {
            size = s;
            int x = (int)ceil(log2(s));
            for (int i = 0; i <= x; i++) {
                arr[i].clear();
            }
            arr[x].push_back(Pair(0, size - 1));
        }

        void allocate(int s) {
            int x = (int)ceil(log2(s));
            int i;
            Pair temp;
            if (!arr[x].empty()) {
                temp = arr[x][0];
                arr[x].erase(arr[x].begin());
                cout << "Memory from " << temp.lb << " to " << temp.ub << " allocated" << endl;
                return;
            }
            for (i = x + 1; i < 100; i++) {
                if (arr[i].empty()) {
                    continue;
                }
                break;
            }
            if (i == 100) {
                cout << "Sorry, failed to allocate memory" << endl;
                return;
            }
            temp = arr[i][0];
            i--;
            for (; i >= x; i--) {
                Pair newPair = Pair(temp.lb, temp.lb + (temp.ub - temp.lb) / 2);
                Pair newPair2 = Pair(temp.lb + (temp.ub - temp.lb + 1) / 2, temp.ub);
                arr[i].push_back(newPair);
                arr[i].push_back(newPair2);
                temp = arr[i][0];
                arr[i].erase(arr[i].begin());
            }
            cout << "Memory from " << temp.lb << " to " << temp.ub << " allocated" << endl;
        }
};

int main() {
    int initialMemory = 0, val = 0;

    cout << "Enter size of hard disk KB : ";
    cin >> initialMemory;

    Buddy obj(initialMemory);

    while (true) {
        cout << "Enter size of process in KB : ";
        cin >> val;
        if (val <= 0) {
            break;
        }
        obj.allocate(val);
    }
    return 0;
}
