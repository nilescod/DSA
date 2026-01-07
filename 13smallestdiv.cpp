//given an array and threshold and the sum of ceil values of a[i]/k should be <= threshold value find k
#include<bits/stdc++.h>
using namespace std;
//OPTIMAL SOLUTION USES TC OF O(N*log(max-min))
int tans(vector<int>&a,int m){
    int n=a.size();int tp=0;
    for(int i=0;i<n;i++){
        tp+=ceil(double(a[i])/double(m));
    }
    return tp;
}
int mindivisor(vector<int>&a,int t){
    int n=a.size();
    int maxi=INT_MIN;
    int mini=INT_MAX;
    for(int i=0;i<n;i++){
        maxi=max(maxi,a[i]);
        mini=min(mini,a[i]);
    }
    int low=mini,high=maxi;int ans=-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(tans(a,mid)<=t){
            ans=mid;
            high=mid-1;
        }else{
            low=mid+1;
        }
    }
    return ans;

}
int main(){
    int n;cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<"enter threshold value: "<<endl;
    int t;cin>>t;
    int mindiv=mindivisor(a,t);
    cout<<mindiv;
}