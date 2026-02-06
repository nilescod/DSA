#include<bits/stdc++.h>
using namespace std;

int f4(int ind,int target,vector<int>&a){
    vector<int>prev(target+1,0),cur(target+1,0);
    prev[0]=cur[0]=1;
    if(a[0]<=target)prev[a[0]]=1;
    
    for(int i=1;i<ind+1;i++){
        for(int k=1;k<=target;k++){
            int notpick=prev[k];
            int pick=0;
            if(a[i]<=k){
                pick=prev[k-a[i]];
            }
            cur[k]=pick+notpick;
        }
        prev=cur;
    }
    return prev[target];
}

int countpartition(int n,int d,vector<int>&a){
    int tsum=0;
    for(int i=0;i<n;i++){
        tsum+=a[i];
    }
    if(tsum<d||(tsum-d)%2) return 0;
    return f4(n-1,(tsum-d)/2,a);
}



int main(){
    int n=4;
    vector<int>a{5,2,6,4};
    cout<<countpartition(n,3,a);
}