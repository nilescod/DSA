#include<bits/stdc++.h>
using namespace std;

//Recursion
int f(int ind,int t,vector<int>&coins){
    if(ind==0){
        if(t%coins[0]==0) return t/coins[0];
        return 1e9;
    }
    int nottake=0+f(ind-1,t,coins);
    int take=1e9;
    if(coins[ind]<=t){
        take=1+f(ind,t-coins[ind],coins);
    }
    return min(take,nottake);
}

int mincoins(vector<int>&coins,int target){
    int n=coins.size();
    return f(n-1,target,coins);
}

//Memoization
int f2(int ind,int t,vector<int>&coins,vector<vector<int>>&dp){
    if(ind==0){
        if(t%coins[0]==0) return t/coins[0];
        return 1e9;
    }
    if(dp[ind][t]!=-1) return dp[ind][t];
    int nottake=0+f2(ind-1,t,coins,dp);
    int take=1e9;
    if(coins[ind]<=t){
        take=1+f2(ind,t-coins[ind],coins,dp);
    }
    return dp[ind][t]=min(take,nottake);
}

int mincoins2(vector<int>&coins,int target){
    int n=coins.size();
    vector<vector<int>>dp(n,vector<int>(target+1,-1));
    return f2(n-1,target,coins,dp);
}

//Tabulation
int f3(int ind,int t,vector<int>&coins,vector<vector<int>>&dp){
    for(int target=0;target<=t;target++){
        if(target%coins[0]==0) dp[0][target]=target/coins[0];
        else dp[0][target]=1e9;
    }

    for(int i=1;i<ind+1;i++){
        for(int target=0;target<=t;target++){
            int nottake=dp[i-1][target];
            int take=1e9;
            if(coins[i]<=target){
                take=1+dp[i][target-coins[i]];
            }
            dp[i][target]=min(take,nottake);
        }
    }
    return dp[ind][t];
}

int mincoins3(vector<int>&coins,int target){
    int n=coins.size();
    vector<vector<int>>dp(n,vector<int>(target+1,0));
    return f3(n-1,target,coins,dp);
}

//Space Optimization
int f4(int ind,int t,vector<int>&coins){
    vector<int>prev(t+1,0),cur(t+1,0);

    for(int target=0;target<=t;target++){
        if(target%coins[0]==0) prev[target]=target/coins[0];
        else prev[target]=1e9;
    }

    for(int i=1;i<ind+1;i++){
        for(int target=0;target<=t;target++){
            int nottake=prev[target];
            int take=1e9;
            if(coins[i]<=target){
                take=1+cur[target-coins[i]];
            }
            cur[target]=min(take,nottake);
        }
        prev=cur;
    }
    return prev[t];
}

int mincoins4(vector<int>&coins,int target){
    int n=coins.size();
    return f4(n-1,target,coins);
}



int main(){
    vector<int>coins{9,6,5,1};
    int target=11;
    cout<<mincoins(coins,target)<<endl;
    cout<<mincoins2(coins,target)<<endl;
    cout<<mincoins3(coins,target)<<endl;
    cout<<mincoins4(coins,target)<<endl;

}
