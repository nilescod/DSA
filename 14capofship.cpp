//given weight array and you have to find least capacity to ship packages within d days
#include<bits/stdc++.h>
using namespace std;
//TC IS O(N*log(sum-max))
int tdays(vector<int>&a,int m){
    int n=a.size();
    int days=1,load=0;
    for(int i=0;i<n;i++){
        if(a[i]+load>m){
            days+=1;
            load=a[i];
        }else{
            load+=a[i];
        }
    }
    return days;
}

int leacap(vector<int>&a,int d){
    int n=a.size();
    int maxi=INT_MIN;int sum=0;
    for(int i=0;i<n;i++){
        maxi=max(maxi,a[i]);
        sum+=a[i];
    }
    int ans=-1;
    int low=maxi,high=sum;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(tdays(a,mid)<=d){
            high=mid-1;
        }else{
            low=mid+1;
        }
    }
    return low;
}
int main(){
    int n;cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<"enter days: ";
    int d;
    cin>>d;
    int least=leacap(a,d);
    cout<<least;
}