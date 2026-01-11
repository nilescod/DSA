#include<bits/stdc++.h>
using namespace std;
int canplace(vector<int>&a,int m){
    int paint=1,pagescnt=0;
    for(int i=0;i<a.size();i++){
        if(a[i]+pagescnt<=m){
            pagescnt+=a[i];
        }else{ 
            paint++;
            pagescnt=a[i];
        }
    }
    return paint;
}
int minofmax(vector<int>&a,int k){
    int n=a.size();
    int sum=0,maxi=INT_MIN;
    for(int i=0;i<n;i++){
        maxi=max(maxi,a[i]);
        sum+=a[i];
    }
    int low=maxi,high=sum;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(canplace(a,mid)>k){
            low=mid+1;
        }else{
            high=mid-1;        }
    }
    return low; 
}
int main(){
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int k;cin>>k;
    cout<<minofmax(a,k);
    
}