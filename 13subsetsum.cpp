#include<bits/stdc++.h>
using namespace std;
//Find if there exists a subsequence with sum k
//Recursion
//TC IS O(2^n) and SC IS O(n)
bool f(int ind,int target,vector<int>&a){
    if(target==0) return true;
    if(ind==0) return (a[ind]==target);
    bool notpick=f(ind-1,target,a);
    bool pick=false;
    if(a[ind]<=target){
        pick=f(ind-1,target-a[ind],a);
    }
    return (pick||notpick);
}
//Memoization
//TC IS O(n*target) and SC IS O(n*target)+O(n)
bool f2(int ind,int target,vector<int>&a,vector<vector<int>>&dp){
    if(target==0) return true;
    if(ind==0) return (a[ind]==target);
    if(dp[ind][target]!=-1) return dp[ind][target];
    bool notpick=f2(ind-1,target,a,dp);
    bool pick=false;
    if(a[ind]<=target){
        pick=f2(ind-1,target-a[ind],a,dp);
    }
    return dp[ind][target]=(pick||notpick);
}
bool subsetsum(int ind,int target,vector<int>&a){
    vector<vector<int>>dp(ind+1,vector<int>(target+1,-1));
    return f2(ind,target,a,dp);
}
//Tabulation
//TC IS O(n*target) and SC IS O(n*target)
bool f3(int ind,int target,vector<int>&a,vector<vector<int>>&dp){
    for(int i=0;i<ind+1;i++) dp[i][0]=true;
    dp[0][a[0]]=true;
    for(int i=1;i<ind+1;i++){
        for(int k=1;k<=target;k++){
            bool notpick=dp[i-1][k];
            bool pick=false;
            if(a[i]<=k) pick=dp[i-1][k-a[i]];
            dp[i][k]=pick||notpick;

        }
    }
    return dp[ind][target];
}

bool subsetsum2(int ind,int target,vector<int>&a){
    vector<vector<int>>dp(ind+1,vector<int>(target+1,0));
    return f3(ind,target,a,dp);
}
//Space Optimization
//TC IS O(n*target) and SC IS O(2*target)
bool f4(int ind,int target,vector<int>&a){
    vector<bool>prev(target+1,0),cur(target+1,0);
    prev[0]=cur[0]=true;
    prev[a[0]]=true;
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
    return f4(ind,target,a);
}


int main(){
    int n=4;
    int target=4;
    vector<int>a{2,3,1,1};
    cout<<f(n-1,target,a)<<endl;
    cout<<subsetsum(n-1,target,a)<<endl;
    cout<<subsetsum2(n-1,target,a)<<endl;
    cout<<subsetsum3(n-1,target,a)<<endl;
}