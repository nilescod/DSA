#include<bits/stdc++.h>
using namespace std;

//Similar to unbounded knapsack problem
//can also be done using memoization,tabulation,double and single array optimization 

int f(int ind,int t,vector<int>&price){
    if(ind==0){
        if(t>=1) return price[0]*t;
        else return -1e8;
    }
    
    int notpick=0+f(ind-1,t,price);
    int pick=-1e8;
    //here rodlength=ind+1
    if(ind+1<=t){
        pick=price[ind]+f(ind,t-ind-1,price);
    }
    return max(pick,notpick);
}

int rodcutting(vector<int>&price,int n){
    int ind=price.size()-1;
    return f(ind,n,price);
}

int main(){
    vector<int>price{2,5,7,8,10};
    int n=5;
    cout<<rodcutting(price,n);
}