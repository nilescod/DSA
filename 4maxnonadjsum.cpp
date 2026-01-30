#include<bits/stdc++.h>
using namespace std;

//maximum sum of non adjacent elements in an array
//Recursive Approach
//TC IS O(2^n)
int maxnonadjsum(int ind,vector<int>&nums){
    if(ind==0) return nums[ind];
    if(ind<0) return 0;
    
    int pick=nums[ind] + maxnonadjsum(ind-2,nums);

    int notpick=0+maxnonadjsum(ind-1,nums);
    return max(pick,notpick);
}

//Memoization
//TC IS O(n) SC IS O(n)+O(n)
int maxnonadjsum2(int ind,vector<int>&nums,vector<int>&dp){
    if(ind==0) return nums[ind];
    if(ind<0) return 0;
    
    if(dp[ind]!=-1) return dp[ind];
    int pick=nums[ind] + maxnonadjsum2(ind-2,nums,dp);

    int notpick=0+maxnonadjsum2(ind-1,nums,dp);
    return dp[ind]=max(pick,notpick);
}

//Tabulation Method
//TC AND SC IS O(n)
int maxNonAdjSum(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n, 0);
    dp[0] = nums[0];

    for (int i = 1; i < n; i++) {
        int pick = nums[i];
        if (i > 1) pick += dp[i - 2];
        int notpick = dp[i - 1];
        dp[i] = max(pick, notpick);
    }

    return dp[n - 1];
}

//Using Space Optimization
//TC IS O(n) and SC IS O(1)
int maxnonadjsum4(vector<int>& nums){
    int n = nums.size();
    int prev = nums[0];
    int prev2=0;

    for (int i = 1; i < n; i++) {
        int pick = nums[i];
        if (i > 1) pick += prev2;
        int notpick = prev;

        int curi=max(pick,notpick);
        prev2=prev;
        prev=curi;
    }

    return prev;
}

int main(){

    vector<int>nums={1,2,4,9};
    cout<<maxnonadjsum(3,nums)<<"\n";
    vector<int>dp(4,-1);
    cout<<maxnonadjsum2(3,nums,dp)<<"\n";
    cout<<maxNonAdjSum(nums)<<"\n";
    cout<<maxnonadjsum4(nums)<<"\n";

}