#include <bits/stdc++.h>
using namespace std;
//Find the length of longest common substring

int f(int i, int j, string &s1, string &s2, int count, int &ans) {
    if (i < 0 || j < 0) return 0;

    int current = 0;
    if (s1[i] == s2[j]) {
        current = 1 + f(i - 1, j - 1, s1, s2, count + 1, ans);
        ans = max(ans, current);
    } else {
        // Reset the length if characters do not match
        f(i - 1, j, s1, s2, 0, ans);
        f(i, j - 1, s1, s2, 0, ans);
    }

    return current;
}

int longestCommonSubstring(string s1, string s2) {
    int ans = 0;
    f(s1.length() - 1, s2.length() - 1, s1, s2, 0, ans);
    return ans;
}

//Tabulation is easier approach
//Can also be further space Optimises using 2 array
int lcs(string s1,string s2){
    int n=s1.length();
    int m=s2.length();
    vector<vector<int>>dp(n+1,vector<int>(m+1,0));
    for(int j=0;j<=m;j++) dp[0][j]=0;
    for(int i=0;i<=n;i++) dp[i][0]=0;
    int ans=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s1[i-1]==s2[j-1]) dp[i][j]=1+dp[i-1][j-1];
            else dp[i][j]=0;
            ans=max(ans,dp[i][j]);
        }
    }
    return ans;

}

int main() {
    string s1 = "abcde";
    string s2 = "abfce";
    cout << longestCommonSubstring(s1, s2) << endl;
    cout<<lcs(s1,s2)<<endl;
    return 0;
}
