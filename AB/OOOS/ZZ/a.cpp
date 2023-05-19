#include<iostream>
#include<vector>
using namespace std;

int fcfs(vector<int>arr, int head){
    int ans=0;
    for(int i=0; i<arr.size(); i++){
        ans+= abs(head-arr[i]);
        head=arr[i];
    }
    return ans;
}
int main(){
    vector<int>track_no;
    int tracks;
    cout<<"Enter no of tracks: ";
    cin>>tracks;
    cout<<"Enter track brtween 0-200: ";
    int a;
    for(int i=0; i<tracks; i++){
        cin>>a;
        track_no.push_back(a);
    }
    cout<<"Enter head pointer: ";
    int head;
    cin>>head;
    int ans=fcfs(track_no, head);
    cout<<"Total No Track Movemnts: "<<ans<<endl;
    return 0;
}