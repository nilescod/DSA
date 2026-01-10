//to understand refer NoteBook
#include<bits/stdc++.h>
using namespace std;
//tc is O(n*log(sum-max+1))
int canplace(vector<int>&a,int m){
    int stud=1,pagescnt=0;
    for(int i=0;i<a.size();i++){
        if(a[i]+pagescnt<=m){
            pagescnt+=a[i];
        }else{
            stud++;
            pagescnt=a[i];
        }
    }
    return stud;
}
int maxstud(vector<int>&a,int stud){
    int n=a.size();
    int sum=0,maxi=INT_MIN;
    for(int i=0;i<n;i++){
        maxi=max(maxi,a[i]);
        sum+=a[i];
    }
    int low=maxi,high=sum;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(canplace(a,mid)>stud){
            low=mid+1;
        }else{
            high=mid-1;        }
    }
    return low;
}
int main(){
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int stud;
    cout<<"enter the no. of students: ";
    cin>>stud;
    cout<<maxstud(a,stud);
}