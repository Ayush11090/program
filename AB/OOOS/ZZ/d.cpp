#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

int sstf(vector<int>v, int head){
    int sum=0;
    while(!v.empty()){
        vector<int>arr(v.size());
        for(int i=0; i<v.size(); i++){
            arr[i]= abs(v[i] - head);
        }
        int min_idx = distance(arr.begin(), min_element(arr.begin(), arr.end()));
        sum+=arr[min_idx];
        head=v[min_idx];
        v.erase(v.begin()+min_idx);
    }
    return sum;
}
int main()
{
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
    int ans = sstf(track_no, curr_pos_head);
    cout << "Total No of Track Movements:"<< ans << endl;
    return 0;
return 0;
}