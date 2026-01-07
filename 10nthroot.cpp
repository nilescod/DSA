#include <bits/stdc++.h>
using namespace std;
//below is the power exponential method with TC of O(logn)
long long f(int mid,int n){
    long long ans=1;
    for(int i=1;i<=n;i++){
        ans*=mid;
    }
    return ans;
}
int nthrootof(int n,int num){
    int low=1;int high=num;
    while(low<=high){
        long long mid=low+(high-low)/2;
        long long val=f(mid,n);
        if(val==num) {return mid;}
        else if(val<num){low=mid+1;}
        else{high=mid-1;}
    }
    return -1;
}
//THE ABOVE CODE WONT WORK FOR A LARGE NUMBER
//try the below code
/*
return 1 if ==m
return 2 if > m
return 0 if < m
*/
long long fun(int mid,int n,int m){
    long long ans=1;
    for(int i=1;i<=n;i++){
        ans*=mid;
        if(ans>m) return 2;

    }
    if(ans==m) return 1;
    return 0;
}
int nthroot(int n,int m){
    int low=1,high=m;
    while(low<=high){
        int mid=low+(high-low)/2;
        int midN=fun(mid,n,m);
        if(midN==1){
            return mid;
        }
        else if(midN==0) {low=mid+1;}
        else{
            high=mid-1;
        }
    }
    return -1;
}
int main(){
    int n;cin>>n;
    int num;cin>>num;
    int nr=nthroot(n,num);
    cout<<nr;

}