#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int SCAN(vector<int>v, int head, int disk_size){
    sort(v.begin(), v.end());
    int ans=0;
    ans = ((disk_size-1)- head) + ((disk_size-1)-v[0]);
    return ans;
    }
int main()
{
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
    int ans=SCAN(track_no, head, 200);
    cout<<"Total No Track Movemnts: "<<ans<<endl;
return 0;
}