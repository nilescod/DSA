#include<bits/stdc++.h>
using namespace std;
//BELOW IS BRUTE SOLUTION
//BRUTE SOLUTION GIVES TC OF O(n*k+n)
long double minimisemaxdistance(vector<int>&a,int k){
    int n=a.size();
    vector<int>howmany(n-1,0);
    for(int gasstations=1;gasstations<=k;gasstations++){
        long double maxSection=-1;
        int maxInd=-1;
        for(int i=0;i<n-1;i++){
            long double diff=a[i+1]-a[i];
            long double sectionLength=diff/(howmany[i]+1);
            if(sectionLength>maxSection){
                maxSection=sectionLength;
                maxInd=i;
            }
        }
        howmany[maxInd]++;
    }
    long double maxAns=-1;
    for(int i=0;i<n-1;i++){
        long double diff=a[i+1]-a[i];
        long double sectionLength=diff/(long double)(howmany[i]+1);
        maxAns=max(maxAns,sectionLength);
    }
    return maxAns;

}
//BELOW IS BETTER SOLUTION
//TC IS O(n*logn+k*logn) and SC IS O(n-1)
long double minimisedist(vector<int>&a,int k){
    int n=a.size();
    vector<int>howMany(n-1,0);
    priority_queue<pair<long double ,int>>pq;
    for(int i=0;i<n-1;i++){
        pq.push({a[i+1]-a[i],i});
    }
    for(int gasStations=1;gasStations<=k;gasStations++){
        auto tp=pq.top();pq.pop();
        int secInd=tp.second;
        howMany[secInd]++;
        long double iniDiff=a[secInd+1]-a[secInd];
        long double newSectionlen=iniDiff/(howMany[secInd]+1);
        pq.push({newSectionlen,secInd});
    }

    return pq.top().first;
}
//BELOW IS OPTIMAL SOLUTION
//TC IS O(n*logn) and SC IS O(1)
int countofgass(long double dist,vector<int>&a){
    int cnt=0;
    for(int i=1;i<a.size();i++){
        int numinbet=((a[i]-a[i-1])/dist);
        if((a[i]-a[i-1])/dist==numinbet*dist){
            numinbet--;
        }
        cnt+=numinbet;
    }
    return cnt;
}
long double minimdist(vector<int>&a,int k){
    int n=a.size();
    long double low=0;
    long double high=0;
    for(int i=0;i<n-1;i++){
        high=max(high,(long double)(a[i+1]-a[i]));
    } 

    long double diff=1e-6;

    //in while condition high-low>10e-6
    while(low+diff<high){
        long double mid=low+(high-low)/2.0;
        int cnt=countofgass(mid,a);
        if(cnt>k) {
            low=mid;
        }
        else{
            high=mid;
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
    int k;cin>>k;
    //cout<<minimisemaxdistance(a,k);
    long double x=minimdist(a,k);
    cout<<x;
    
}   