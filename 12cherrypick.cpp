#include<bits/stdc++.h>
using namespace std;
//TC IS O(3^n*3^n) and SC IS O(n)
int f(int i,int j1,int j2,int r,int c,vector<vector<int>>&grid){
    if(j1<0||j2<0||j1>=c||j2>=c){
        return -1e8;
    }
    if(i==r-1){
        if(j1==j2) return grid[i][j1];
        else return grid[i][j1]+grid[i][j2];
    }

    int maxi=-1e8;
    for(int dj1=-1;dj1<=1;dj1++){
        for(int dj2=-1;dj2<=1;dj2++){
            int val=0;
            if(j1==j2) val=grid[i][j1];
            else val=grid[i][j1]+grid[i][j2];
            val+=f(i+1,j1+dj1,j2+dj2,r,c,grid);
            maxi=max(maxi,val);
        }
    }
    return maxi;
}

int cherrypickup(int r,int c,vector<vector<int>>&grid){
    return f(0,0,c-1,r,c,grid);
}


//Memoization
//TC IS O(n*m*m)*9 and SC IS O(n*m*m)+O(n) for recursive stack space
int f2(int i,int j1,int j2,int r,int c,vector<vector<int>>&grid){
    vector<vector<vector<int>>>dp(r,vector<vector<int>>(c,vector<int>(c,-1)));
    if(j1<0||j2<0||j1>=c||j2>=c){
        return -1e8;
    }
    if(i==r-1){
        if(j1==j2) return grid[i][j1];
        else return grid[i][j1]+grid[i][j2];
    }
    if(dp[i][j1][j2]!=-1) return dp[i][j1][j2];

    int maxi=-1e8;
    for(int dj1=-1;dj1<=1;dj1++){
        for(int dj2=-1;dj2<=1;dj2++){
            int val=0;
            if(j1==j2) val=grid[i][j1];
            else val=grid[i][j1]+grid[i][j2];
            val+=f2(i+1,j1+dj1,j2+dj2,r,c,grid);
            maxi=max(maxi,val);
        }
    }
    return dp[i][j1][j2]=maxi;
}

int cherrypickup2(int r,int c,vector<vector<int>>&grid){
    return f(0,0,c-1,r,c,grid);
}
//Tabulation
//TC IS O((n*m*m)*9) and SC IS O(n*m*m)
int maximumChocolates(int n, int m, vector<vector<int>> &grid) {
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, 0)));

    for (int j1 = 0; j1 < m; j1++) {
        for (int j2 = 0; j2 < m; j2++) {
            if (j1 == j2)
                dp[n - 1][j1][j2] = grid[n - 1][j1];
            else
                dp[n - 1][j1][j2] = grid[n - 1][j1] + grid[n - 1][j2];
        }
    }

    for (int i = n - 2; i >= 0; i--) {
        for (int j1 = 0; j1 < m; j1++) {
            for (int j2 = 0; j2 < m; j2++) {
                int maxi = INT_MIN;

                for (int di = -1; di <= 1; di++) {
                    for (int dj = -1; dj <= 1; dj++) {
                        int ans;

                        if (j1 == j2)
                            ans = grid[i][j1];
                        else
                            ans = grid[i][j1] + grid[i][j2];

                        if ((j1 + di < 0 || j1 + di >= m) || (j2 + dj < 0 || j2 + dj >= m))
                            ans += -1e9; 
                        else
                            ans += dp[i + 1][j1 + di][j2 + dj]; 
                        maxi = max(ans, maxi); 
                    }
                }
                dp[i][j1][j2] = maxi; 
            }
        }
    }
    return dp[0][0][m - 1];
}


int main(){
    int r=3,c=4;
    vector<vector<int>>grid{{2,3,1,2},{3,4,2,2},{5,6,3,5}};
    cout<<cherrypickup(r,c,grid);
}