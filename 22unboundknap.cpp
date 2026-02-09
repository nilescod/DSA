#include<bits/stdc++.h>
using namespace std;
//Unbounded Knapsack Problem
//there are infinite supply of each occurence

int f(int ind,int target,vector<int>&weight,vector<int>&value){
    if(ind==0){
        if(weight[0]<=target) return value[0]*(target/weight[0]);
        else return -1e8;
    }
    int notpick=f(ind-1,target,weight,value);
    int pick=-1e8;
    if(weight[ind]<=target){
        pick=value[ind]+f(ind,target-weight[ind],weight,value);
    }
    return max(pick,notpick);
}

int unboundedks(vector<int>&weight,vector<int>&value,int target){
    int n=weight.size();
    return f(n-1,target,weight,value);
}

//Memoization

int f2(int ind,int target,vector<int>&weight,vector<int>&value,vector<vector<int>>&dp){
    if(ind==0){
        if(weight[0]<=target) return value[0]*(target/weight[0]);
        else return -1e8;
    }
    if(dp[ind][target]!=-1) return dp[ind][target];
    int notpick=f2(ind-1,target,weight,value,dp);
    int pick=-1e8;
    if(weight[ind]<=target){
        pick=value[ind]+f2(ind,target-weight[ind],weight,value,dp);
    }
    return dp[ind][target]=max(pick,notpick);
}

int unboundedks2(vector<int>&weight,vector<int>&value,int target){
    int n=weight.size();
    vector<vector<int>>dp(n,vector<int>(target+1,-1));
    return f2(n-1,target,weight,value,dp);
}

//This can also be further space optimised using Tabulation,using 2 array method and then into single array method

//Space Optimised using 2 array
int unboundedks3(int ind,int target,vector<int>&weight,vector<int>&value){
    vector<int>prev(target+1,0),cur(target+1,0);
    for(int w=0;w<=target;w++){
        prev[w]=((int)(w/weight[0]))*value[0];
    }
    for(int i=1;i<=ind;i++){
        for(int w=0;w<=target;w++){
            int notpick=0+prev[w];
            int pick=0;
            if(weight[i]<=w){
                pick=value[i]+cur[w-weight[i]];
            }
            cur[w]=max(pick,notpick);
        }
        prev=cur;
    }
    return prev[target];
}

//Space Optimised using 1 array
int unboundedks4(int ind,int target,vector<int>&weight,vector<int>&value){
    vector<int>prev(target+1,0);
    for(int w=0;w<=target;w++){
        prev[w]=((int)(w/weight[0]))*value[0];
    }
    for(int i=1;i<=ind;i++){
        for(int w=0;w<=target;w++){
            int notpick=0+prev[w];
            int pick=0;
            if(weight[i]<=w){
                pick=value[i]+prev[w-weight[i]];
            }
            prev[w]=max(pick,notpick);
        }
    }
    return prev[target];
}

int main(){
    vector<int>weight{2,4,6},value{5,11,13};
    int target=10;
    cout<<unboundedks(weight,value,target)<<endl;
    cout<<unboundedks2(weight,value,target)<<endl;
    cout<<unboundedks3(2,target,weight,value)<<endl;
    cout<<unboundedks4(2,target,weight,value)<<endl;
}