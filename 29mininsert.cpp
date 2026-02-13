#include<bits/stdc++.h>
using namespace std;
//Minimum operations to convert string 1 to string 2 (insertions+deletions)
int f3(int ind1,int ind2,string s1,string s2,vector<vector<int>>&dp){

    for(int i=0;i<=ind1;i++) dp[i][0]=0;
    for(int j=0;j<=ind2;j++) dp[0][j]=0;
    for(int i=1;i<ind1+1;i++){
        for(int j=1;j<ind2+1;j++){
            if(s1[i]==s2[j]) dp[i][j]=1+dp[i-1][j-1];
            else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    return dp[ind1][ind2];
}

int lcs3(string s1,string s2){
    int n1=s1.length();
    int n2=s2.length();
    vector<vector<int>>dp(n1+1,vector<int>(n2+1,0));
    return f3(n1,n2,s1,s2,dp);
    //To write our base case we make this dp array of size((n+1)*(m+1))
}

int minoper(string s1,string s2){
    int n=s1.length();
    int m=s2.length();
    int deletions=n-lcs3(s1,s2);
    int insertions=m-lcs3(s1,s2);
    return deletions+insertions;
}

int main(){
    string s1="abcd";
    string s2="anc";
    cout<<minoper(s1,s2);
}