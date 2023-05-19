#include<iostream>
#include <bits/stdc++.h>
using namespace std;


int main(){
    int t;
    cout<<"enter the number of tracks: ";
    cin >> t;
    int n;
    cout<<"enter no. of requests: ";
    cin>>n;
    vector<int> request(n);
    cout<<"Enter the request sequence: ";
    for(int i=0;i<n;i++){
        cin>>request[i];
    }
    
    int chp;
    cout<< "enter the current head ponter : ";
    cin >> chp;
    
    sort(request.begin(), request.end());
    int index=0;
    for(int i=0;i<n;i++){
        if(request[i]>=chp){
            index=i;
            break;
        }
    }
    int dir;
    cout<<"Enter the direction 0 -> clockwise & 1->anticlockwise: ";
    cin>>dir;
    
    int n_tracks=0;
    if(dir==0){
        for(int i=index;i<n;i++){
            n_tracks+=(request[i]-chp);
            chp=request[i];
        }
        
        for(int i=index-1;i>=0;i--){
            n_tracks+=(chp - request[i]);
            chp=request[i];
        }
    }
    else{
        for(int i=index-1;i>=0;i--){
            n_tracks+=(chp - request[i]);
            chp=request[i];
        }
        for(int i=index;i<n;i++){
            n_tracks+=(request[i]-chp);
            chp=request[i];
        }
    }
    
    cout<<"Total no. of track(sum): "<<n_tracks<<endl;
    return 0;

}