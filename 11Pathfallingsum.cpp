#include<bits/stdc++.h>
using namespace std;
//Find Maximum Path falling Sum from 1st row to bottom row
//Recursive

int f(int i,int j,vector<vector<int>>&triangle){
    int m=triangle[0].size();
    if(j<0 || j>=m) 
        return -1e8;
    if(i==0) return triangle[0][j];
    int s=triangle[i][j]+f(i-1,j,triangle);        
    int ld=triangle[i][j]+f(i-1,j-1,triangle);        
    int rd=triangle[i][j]+f(i-1,j+1,triangle);
    return max(s,max(ld,rd));
}

int maxpathsum(vector<vector<int>>&a,int n){
    int m=a[0].size();
    int maxi=-1e8;
    for(int j=0;j<n;j++){
        maxi=max(maxi,f(n-1,j,a));//we are checking max sum for every element from the last row
    }
    return maxi; 
}

//Memoization
int f2(int i,int j,vector<vector<int>>&triangle,vector<vector<int>>&dp){
    int m=triangle[0].size();
    if(j<0 || j>=m) 
        return -1e8;
    if(i==0) return triangle[0][j];
    if(dp[i][j]!=-1) return dp[i][j]; 
    int s=triangle[i][j]+f2(i-1,j,triangle,dp);        
    int ld=triangle[i][j]+f2(i-1,j-1,triangle,dp);        
    int rd=triangle[i][j]+f2(i-1,j+1,triangle,dp);
    return dp[i][j]=max(s,max(ld,rd));
}

int maxpathsum2(vector<vector<int>>&a,int n){
    int m=a[0].size();
    vector<vector<int>>dp(n,vector<int>(m,-1));
    int maxi=-1e8;
    for(int j=0;j<m;j++){
        maxi=max(maxi,f2(n-1,j,a,dp));//we are checking max sum for every element from the last row
    }
    return maxi; 
}

//Tabulation
int maxpathsum3(vector<vector<int>>&a,int n){
    int m=a[0].size();
    vector<vector<int>>dp(n,vector<int>(m,0));
    for(int j=0;j<m;j++){
        dp[0][j]=a[0][j];
    }
    for(int i=1;i<n;i++){
        for(int j=0;j<m;j++){
            int s=a[i][j]+dp[i-1][j];            
            int ld=a[i][j];
            if(j>=1) ld+=dp[i-1][j-1];
            else ld+=-1e8;         
            int rd=a[i][j];
            if(j<m-1) rd+=dp[i-1][j+1];
            else rd+=-1e8; 
            dp[i][j]=max(s,max(ld,rd));
        }
    }
    int maxi=-1e8;
    for(int j=0;j<m;j++){
        maxi=max(maxi,dp[n-1][j]);
    }
    return maxi;
}
//Space Optimization
int maxpathsum4(vector<vector<int>>&a,int n){
    int m=a[0].size();
    vector<int>prev(m,0),cur(m,0);
    for(int j=0;j<m;j++){
        prev[j]=a[0][j];
    }
    for(int i=1;i<n;i++){
        for(int j=0;j<m;j++){
            int s=a[i][j]+prev[j];            
            int ld=a[i][j];
            if(j>=1) ld+=prev[j-1];
            else ld+=-1e8;         
            int rd=a[i][j];
            if(j<m-1) rd+=prev[j+1];
            else rd+=-1e8; 
            cur[j]=max(s,max(ld,rd));
        }
        prev=cur;
    }
    int maxi=-1e8;
    for(int j=0;j<m;j++){
        maxi=max(maxi,prev[j]);
    }
    return maxi;
}


int main(){
    int n=4;
    vector<vector<int>>a{{1,2,10,4},{100,3,2,1},{1,1,20,2},{1,2,2,1}};
    cout<<maxpathsum(a,n)<<endl;
    cout<<maxpathsum2(a,n)<<endl;
    cout<<maxpathsum3(a,n)<<endl;
    cout<<maxpathsum4(a,n)<<endl;
    

}