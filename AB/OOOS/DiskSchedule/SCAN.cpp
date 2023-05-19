#include<bits/stdc++.h>
using namespace std;

int SCAN(vector<int>v, int head, int disk_size, string direction){
 sort(v.begin(), v.end());
    int ans=0;
    if(direction =="clockwise"){
     ans = ((disk_size-1)-head)+((disk_size-1)-v[0]);
}
    else{
         ans= head + v[v.size()-1];
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
    string direction;
    cout<<"Enter the direction:";
    cin>>direction;
    cout<<"Enter the value of head pointer:";
    int curr_pos_head;
    cin>>curr_pos_head;
    int ans=SCAN(track_no,curr_pos_head,200,direction);
    cout << "Total No of Track Movements:"<< ans << endl;
return 0;
}
