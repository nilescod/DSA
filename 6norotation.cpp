#include <bits/stdc++.h>
using namespace std;
//Find the number of rotations
//find the minimum of the rotated sorted array and return its index
int findrot(vector<int>&arr,int n){
    int index=INT_MAX;
    int low=0;int high=n-1;
    int ans=INT_MAX;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(arr[low]<=arr[high]){
            if(arr[low]<ans){
                index=low;
                ans=arr[low];
            }
            break;
        }
        
        if(arr[mid]>=arr[low]){
            if(arr[low]<ans){
                index=low;
                ans=arr[low];
            }
            low=mid+1;
        }else{
            high=mid-1;
            if(arr[mid]<ans){
                index=mid;
                ans=arr[mid];
            }
        }
    }
    return index;
}
int main(){
    int n;cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++){cin>>a[i];}
    int ind=findrot(a,n);
    cout<<ind;
    
}