#include <bits/stdc++.h>
using namespace std;
//find peak element which is greater than its adjacent array elements
int findpeak(vector<int>&arr,int n){
    if(n==1) return 0;
    if(arr[n-1]>arr[n-2]) return  n-1;
    int low=1;int high=n-2;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1]) {return arr[mid];}
        else if(arr[mid]>arr[mid-1]) {low=mid+1;}
        else high=mid-1;
    }
    return -1;
}

int main(){
    int n;cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++){cin>>a[i];}
    int f=findpeak(a,n);
    cout<<f;    
}