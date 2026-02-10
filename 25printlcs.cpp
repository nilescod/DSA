#include<bits/stdc++.h>
using namespace std;

string f3(int ind1,int ind2,string s1,string s2,vector<vector<int>>&dp){

    for(int i=0;i<=ind1;i++) dp[i][0]=0;
    for(int j=0;j<=ind2;j++) dp[0][j]=0;
    for(int i=1;i<ind1+1;i++){
        for(int j=1;j<ind2+1;j++){
            if(s1[i-1]==s2[j-1]) dp[i][j]=1+dp[i-1][j-1];
            else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    int len=dp[ind1][ind2];
    string ans="";
    for(int i=0;i<len;i++){
        ans+='$';
    }
    int index=len-1;
    int i=ind1,j=ind2;
    while(i>0 && j>0){
        if(s1[i-1]==s2[j-1]){
            ans[index]=s1[i-1];
            index--;
            i--;j--;
        }
        else if(dp[i-1][j]>dp[i][j-1]){
            i--;
        }else{
            j--;
        }
    }
    return ans;
}

string lcs3(string s1,string s2){
    int n1=s1.length();
    int n2=s2.length();
    vector<vector<int>>dp(n1+1,vector<int>(n2+1,0));
    return f3(n1,n2,s1,s2,dp);
    //To write our base case we make this dp array of size((n+1)*(m+1))
}


int main(){
    string s1,s2;
    s1="abcde";
    s2="bdgek";
    cout<<lcs3(s1,s2)<<endl;
}