#include<bits/stdc++.h>
using namespace std;
//ROTATE ARRAY BY ONE PLACE
//tc is O(n) and sc is O(n) with an extra space of O(1)
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int temp=a[0];
    for(int i=1;i<n;i++){
        a[i-1]=a[i];
    }
    a[n-1]=temp;

}

//THIS IS BETTER SOLUTION
//ROTATE ARRAY BY D PLACEs
//tc is O(n+d)(d+(n-d)+d) and sc is O(n) with an extra space of O(d)
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<"enter the number of places to rotate:\n";
    int d;cin>>d;
    d=d%n;
    //first a temp array is created 
    int temp[d];
    for(int i=0;i<d;i++){
        temp[i]=a[i];
    }
    for(int i=d;i<n;i++){
        a[i-d]=a[i];
    }
    int j=0;
    for(int i=n-d;i<n;i++){
        a[i]=temp[j];j++;
    } 
    cout<<"after rotation:\n";
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }

  

}
//
//THIS IS OPTIMAL SOLUTION
//ROTATE ARRAY BY D PLACEs
//tc is O(2n)(d+(n-d)+n) and sc is O(1) with an extra space of O(1)

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"enter the number of places to rotate:\n";
    int d;cin>>d;
    d=d%n;
    reverse(arr,arr+d);
    reverse(arr+d,arr+n);
    reverse(arr,arr+n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }


}
