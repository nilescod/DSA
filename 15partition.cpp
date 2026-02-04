#include<bits/stdc++.h>
using namespace std;

int minsubsetdiff(vector<int>&a,int n){
    int tsum=0;
    for(int i=0;i<n;i++) tsum+=a[i];
    int target=tsum;
    vector<vector<bool>>dp(n,vector<bool>(target+1,0));
    for(int i=0;i<n;i++) dp[i][0]=true;
    if(a[0]<=target) dp[0][a[0]]=true;
    for(int i=1;i<n;i++){
        for(int k=1;k<=target;k++){
            bool notpick=dp[i-1][k];
            bool pick=false;
            if(a[i]<=k) pick=dp[i-1][k-a[i]];
            dp[i][k]=pick||notpick;
        }
    }
    int mini=1e9;
    for(int s1=0;s1<tsum/2;s1++){
        if(dp[n-1][s1]==true){
            mini=min(mini,abs(tsum-s1-s1));
        }
    }
    return mini;
}

int main(){
    int n=6;
    //int target=4;
    vector<int>a{2,3,3,3,4,5};
    cout<<minsubsetdiff(a,n);

}