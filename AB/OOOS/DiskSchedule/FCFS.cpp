#include <iostream>
#include<vector>
using namespace std;

int fcfs(vector<int>arr, int head){
    int ans = 0;
    for(int i = 0; i < arr.size(); i++){
        ans += abs(head - arr[i]);
        head = arr[i];
    }
    return ans;
}

int main() {
    vector<int>track_no;
    int num_track;
    cout<<"Enter the no of tracks:";
    cin>>num_track;
    cout<< "Enter the track nos between 0-200:";
    int a;
    for(int i=0; i<num_track;i++){
        cin>>a;
        track_no.push_back(a);
    }
    cout<<"Enter the value of head pointer:";
    int curr_pos_head;
    cin>>curr_pos_head;
    int ans = fcfs(track_no, curr_pos_head);
    cout << "Total No of Track Movements:"<< ans << endl;
    return 0;
}
