#include<bits/stdc++.h>
using namespace std;

//Recursive Approach
int f(int ind,int mwt,vector<int>&wt,vector<int>&val){
    if(ind==0){
        if(wt[0]<=mwt) return val[0];
        else return 0;
    }
    int notpick=0+f(ind-1,mwt,wt,val);
    int pick=-1e8;
    if(wt[ind]<=mwt){
        pick=val[ind]+f(ind-1,mwt-wt[ind],wt,val);
    }
    return max(pick,notpick);
}

int knapsack(vector<int>&wt,vector<int>&val,int n,int mwt){
    return f(n-1,mwt,wt,val);
}

//Memoization 
int f2(int ind,int mwt,vector<int>&wt,vector<int>&val,vector<vector<int>>&dp){
    if(ind==0){
        if(wt[0]<=mwt) return val[0];
        else return 0;
    }
    if(dp[ind][mwt]!=-1) return dp[ind][mwt];
    int notpick=0+f2(ind-1,mwt,wt,val,dp);
    int pick=-1e8;
    if(wt[ind]<=mwt){
        pick=val[ind]+f2(ind-1,mwt-wt[ind],wt,val,dp);
    }
    return dp[ind][mwt]=max(pick,notpick);
}


int knapsack2(vector<int>&wt,vector<int>&val,int n,int mwt){
    vector<vector<int>>dp(n,vector<int>(mwt+1,-1));
    return f2(n-1,mwt,wt,val,dp);
}

//Tabulation
int f3(int ind,int mwt,vector<int>&wt,vector<int>&val,vector<vector<int>>&dp){
    //Base Cases
    for(int w=wt[0];w<=mwt;w++){dp[0][w]=val[0];}
    
    for(int i=1;i<=ind;i++){
        for(int w=0;w<=mwt;w++){
            int notpick=0+dp[i-1][w];
            int pick=-1e8;
            if(wt[i]<=w){
                pick=val[i]+dp[i-1][w-wt[i]];
            }
            dp[i][w]=max(pick,notpick);
        }
    }
    return dp[ind][mwt];
}

int knapsack3(vector<int>&wt,vector<int>&val,int n,int mwt){
    vector<vector<int>>dp(n,vector<int>(mwt+1,0));
    return f3(n-1,mwt,wt,val,dp);
}

//Space Optimization
int f4(int ind,int mwt,vector<int>&wt,vector<int>&val){
    vector<int>prev(mwt+1,0),cur(mwt+1,0);
    //Base Cases
    for(int w=wt[0];w<=mwt;w++){prev[w]=val[0];}
    
    for(int i=1;i<=ind;i++){
        for(int w=0;w<=mwt;w++){
            int notpick=0+prev[w];
            int pick=-1e8;
            if(wt[i]<=w){
                pick=val[i]+prev[w-wt[i]];
            }
            cur[w]=max(pick,notpick);
        }
        prev=cur;
    }
    return prev[mwt];
}

int knapsack4(vector<int>&wt,vector<int>&val,int n,int mwt){
    return f4(n-1,mwt,wt,val);
}

//Space Optimised Using 1 array

int f5(int ind,int mwt,vector<int>&wt,vector<int>&val){
    vector<int>prev(mwt+1,0);
    //Base Cases
    for(int w=wt[0];w<=mwt;w++){prev[w]=val[0];}
    
    for(int i=1;i<=ind;i++){
        for(int w=mwt;w>=0;w--){
            int notpick=0+prev[w];
            int pick=-1e8;
            if(wt[i]<=w){
                pick=val[i]+prev[w-wt[i]];
            }
            prev[w]=max(pick,notpick);
        }
    }
    return prev[mwt];
}

int knapsack5(vector<int>&wt,vector<int>&val,int n,int mwt){
    return f5(n-1,mwt,wt,val);
}

int main(){
    vector<int>wt{3,2,5};
    vector<int>val{30,40,60};
    int n=wt.size();
    cout<<knapsack(wt,val,n,6)<<endl;
    cout<<knapsack2(wt,val,n,6)<<endl;
    cout<<knapsack3(wt,val,n,6)<<endl;
    cout<<knapsack4(wt,val,n,6)<<endl;
    cout<<knapsack5(wt,val,n,6)<<endl;
}
