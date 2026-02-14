#include<bits/stdc++.h>
using namespace std;
//Find all the distinct subsequences of string s2 in s1
//Recursive Approach
//TC IS O((2^n)*(2^m)) and SC IS O(n+m)
int f(int i,int j,string s1,string s2){
    if(j<0) return 1;
    if(i<0) return 0;
    if(s1[i]==s2[j]) return f(i-1,j-1,s1,s2)+f(i-1,j,s1,s2);
    else return f(i-1,j,s1,s2);
}

int distinctsubseq(string s1,string s2){
    int n=s1.size();
    int m=s2.size();
    return f(n,m,s1,s2);
}
//Memoization
//TC IS O(n*m) and SC IS O(n*m)+O(n+m)
int f2(int i,int j,string s1,string s2,vector<vector<int>>&dp){
    if(j<0) return 1;
    if(i<0) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    if(s1[i]==s2[j]) return dp[i][j]=f2(i-1,j-1,s1,s2,dp)+f2(i-1,j,s1,s2,dp);
    return dp[i][j]=f2(i-1,j,s1,s2,dp);
}

int distinctsubseq2(string s1,string s2){
    int n=s1.size();
    int m=s2.size();
    vector<vector<int>>dp(n,vector<int>(m,-1));
    return f2(n-1,m-1,s1,s2,dp);
}

//Tabulation
int f3(int i,int j,string s1,string s2,vector<vector<int>>&dp){
    for(int ind1=0;ind1<=i;ind1++){
        dp[ind1][0]=1;
    }
    for(int ind2=1;ind2<=j;ind2++){//here dp[0][0]=1 that is why we take j from 1
        dp[0][ind2]=0;
    }
    for(int ind1=1;ind1<=i;ind1++){
        for(int ind2=1;ind2<=j;ind2++){
            if(s1[ind1-1]==s2[ind2-1]) dp[ind1][ind2]=dp[ind1-1][ind2-1]+dp[ind1-1][ind2];
            else dp[ind1][ind2]=dp[ind1-1][ind2];
        }
    }
    return dp[i][j];
}

int distinctsubseq3(string s1,string s2){
    int n=s1.size();
    int m=s2.size();
    vector<vector<int>>dp(n+1,vector<int>(m+1,0));
    return f3(n,m,s1,s2,dp);
}
//Space Optimization
int f4(int i,int j,string s1,string s2){
    vector<int>prev(j+1,0),cur(j+1,0);
    prev[0]=cur[0]=1;
    for(int ind2=1;ind2<=j;ind2++){//here dp[0][0]=1 that is why we take j from 1
        prev[ind2]=0;
    }
    for(int ind1=1;ind1<=i;ind1++){
        for(int ind2=1;ind2<=j;ind2++){
            if(s1[ind1-1]==s2[ind2-1]) cur[ind2]=prev[ind2-1]+prev[ind2];
            else cur[ind2]=prev[ind2];
        }
        prev=cur;
    }
    return prev[j];
}

int distinctsubseq4(string s1,string s2){
    int n=s1.size();
    int m=s2.size();
    return f4(n,m,s1,s2);
}
//1 array Space Optimization
int f5(int i,int j,string s1,string s2){
    vector<int>prev(j+1,0);
    prev[0]=1;
    for(int ind2=1;ind2<=j;ind2++){//here dp[0][0]=1 that is why we take j from 1
        prev[ind2]=0;
    }
    for(int ind1=1;ind1<=i;ind1++){
        for(int ind2=j;ind2>0;ind2--){
            if(s1[ind1-1]==s2[ind2-1]) prev[ind2]=prev[ind2-1]+prev[ind2];
            //else prev[ind2]=prev[ind2];
        }

    }
    return prev[j];
}

int distinctsubseq5(string s1,string s2){
    int n=s1.size();
    int m=s2.size();
    return f5(n,m,s1,s2);
}


int main(){
    string s1="babgbag";
    string s2="bag";
    cout<<distinctsubseq(s1,s2)<<endl;
    cout<<distinctsubseq2(s1,s2)<<endl;
    cout<<distinctsubseq3(s1,s2)<<endl;
    cout<<distinctsubseq4(s1,s2)<<endl;
    cout<<distinctsubseq5(s1,s2)<<endl;
}