#include<bits/stdc++.h>
using namespace std;
                                
//recursive approach
int f(int ind,vector<int>&heights){
    if(ind==0) return 0;

    int left=f(ind-1,heights) + abs(heights[ind]-heights[ind-1]);
    int right=INT_MAX;

    if(ind>1)   { right=f(ind-2,heights) + abs(heights[ind]-heights[ind-2]);}

    return min(left,right);
}

//Memoization
//TC IS O(n) and SC IS O(n)+O(n) for recursion stack space
int memoiz(int ind,vector<int>&heights,vector<int>&dp){
    if(ind==0) return 0;

    if(dp[ind]!=-1) return dp[ind];
    int left=memoiz(ind-1,heights,dp) + abs(heights[ind]-heights[ind-1]);
    int right=INT_MAX;

    if(ind>1)   { right=memoiz(ind-2,heights,dp) + abs(heights[ind]-heights[ind-2]);}

    return dp[ind]=min(left,right);
}

//Tabulation
//TC IS O(n) and SC IS O(n)
int tabul(int ind,vector<int>&heights,vector<int>&dp){
    dp[0]=0;
    dp[1]=abs(heights[1]-heights[0]);

    for(int i=2;i<heights.size()+1;i++){
        int fs=dp[i-1]+abs(heights[i]-heights[i-1]);
        int ss=dp[i-2]+abs(heights[i]-heights[i-2]);
        dp[i]=min(fs,ss);
    }

    return dp[heights.size()-1];
}
//again space optimization can be done using prev and prev2 variables

//if the frog could jump upto k stairs 
//TC IS O(n*k) and SC IS O(n)
int frogJumpK(int n, int k, vector<int>& heights) {
    vector<int> dp(n, 0);
    dp[0] = 0;

    for (int i = 1; i < n; i++) {
        int minEnergy = INT_MAX;
        for (int j = 1; j <= k; j++) {
            if (i - j >= 0) {
                int cost = dp[i - j] + abs(heights[i] - heights[i - j]);
                minEnergy = min(minEnergy, cost);
            }
        }
        dp[i] = minEnergy;
    }

    return dp[n - 1];
}
//Space Optimization can happen upto O(k)
int main(){
    int n=6;
    vector<int>heights={30,10,60,10,60,50};
    vector<int>dp(n+1,-1);
    cout<<memoiz(n-1,heights,dp)<<"\n";int ind;
    cout<<tabul(ind,heights,dp);

}