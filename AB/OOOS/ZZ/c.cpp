#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int C_SCAN(vector<int>v, int head, int disk_size){
    sort(v.begin(),v.end());
    int k=0;
    for(int i=0; i<v.size(); i++){
        if(v[i]>=head){
            k=i;
            break;
        }
    }
    int ans= ((disk_size-1)- head) + (disk_size-1) + v[k-1];
    return ans;
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
    string direction;
    cout<<"Enter the direction:";
    cin>>direction;
    cout<<"Enter the value of head pointer:";
    int curr_pos_head;
    cin>>curr_pos_head;
    int ans=C_SCAN(track_no,curr_pos_head,200);
    cout << "Total No of Track Movements:"<< ans << endl;
  return 0;
}