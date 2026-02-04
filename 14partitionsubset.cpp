#include<bits/stdc++.h>
using namespace std;
//Find if the array can be partitioned into two subsets with equal sum
bool f4(int ind,int target,vector<int>&a){
    vector<bool>prev(target+1,0),cur(target+1,0);
    prev[0]=cur[0]=true;
    if(a[0]<=target) prev[a[0]]=true;
    for(int i=1;i<ind+1;i++){
        for(int k=1;k<=target;k++){
            bool notpick=prev[k];
            bool pick=false;
            if(a[i]<=k) pick=prev[k-a[i]];
            cur[k]=pick||notpick;
        }
        prev=cur;   
    }
    return prev[target];
}

bool subsetsum3(int ind,int target,vector<int>&a){
    int tsum=0;
    for(int i=0;i<ind+1;i++){
        tsum+=a[i];
    }
    if(tsum%2!=0) return false;
    else{
    return f4(ind,tsum/2,a);
    }
}

int main(){
    int n=6;
    int target=4;
    vector<int>a{2,3,3,3,4,5};
    cout<<subsetsum3(n-1,target,a);
}