#include<bits/stdc++.h>
using namespace std;

int address_map(int va, int n, int a[], int pagesize){
    //n->pagetable entries
    int ans=0;
    float d= (float)va;
    int b= ceil(d/pagesize);
    if(b>n){
        cout<<"Invalid Pagefault";
    }
    else{
        ans= a[b-1]*pagesize + va % pagesize;
    }
    return ans;
}
int main(){
  cout<<"Enter virtual address: "<<endl;
  int va;
  cin>>va;
  cout<<"Enter toal page table entries: "<<endl;
  int n;
  cin>>n;
  cout<<"Enter page table Entries: "<<endl;
  int a[n];
  for(int i=0; i<n; i++){
    cin>> a[i];
  }
  int pagesize;
  cout<<"Pagesize"<<endl;
  cin>>pagesize;
  cout<<"RA: "<<address_map(va, n, a, pagesize);


return 0;
}