//find the max of min dist adjustments in the cow array 
#include<bits/stdc++.h>
using namespace std;
//brute gives tc of O(n*n)
//OPTIMAL GIVES TC OF O(n*(log(max-min)))
bool canplace(vector<int>&a,int dist,int cows){
    int n=a.size();
    int cnt=1,last=a[0];
    for(int i=1;i<n;i++){
        if(a[i]-last>=dist){
            cnt++;
            last=a[i];
        }
    }
    if(cnt>=cows) return true;
    else return false;
}
int mindist(vector<int>&a,int cows){
    int n=a.size();
    sort(a.begin(),a.end());
    
    int low=1,high=a[n-1]-a[0];
    while(low<=high){
        int mid=low+(high-low)/2;
        if(canplace(a,mid,cows)==true){
            low=mid+1;
        }else{
            high=mid-1;
        }
    }
    return high;
}

int main(){
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int cows;
    cout<<"enter the no. of cows: ";
    cin>>cows;
    cout<<mindist(a,cows);

}
