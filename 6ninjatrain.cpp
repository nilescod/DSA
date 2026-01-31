#include<bits/stdc++.h>
using namespace std;
//NINJA TRAINING
//Recursive Approach
//TC IS O(2^n) and SC IS O(n)
int f(int day,int last,vector<vector<int>>&points){
    if(day==0){
        int maxi=0;
        for(int i=0;i<3;i++){
            if(i!=last){
                maxi=max(maxi,points[0][i]);
            }
        }
        return maxi;
    }
    int maxi=0;
    for(int task=0;task<3;task++){
        if(task!=last){
            int point=points[day][task]+f(day-1,task,points);
            maxi=max(maxi,point); 
        }
    }
    return maxi;
}

int ninjatrain(int n,vector<vector<int>>&points){
    return f(n-1,3,points);
}
//Memoization
//TC IS O((n*4)*3)
//SC IS O(n)+O(n*4)
int f2(int day,int last,vector<vector<int>>&points,vector<vector<int>>&dp){
    if(day==0){
        int maxi=0;
        for(int i=0;i<3;i++){
            if(i!=last){
                maxi=max(maxi,points[0][i]);
            }
        }
        return maxi;
    }
    if(dp[day][last]!=-1) return dp[day][last];
    int maxi=0;
    for(int task=0;task<3;task++){
        if(task!=last){
            int point=points[day][task]+f2(day-1,task,points,dp);
            maxi=max(maxi,point); 
        }
    }
    return dp[day][last]=maxi;
}
int ninjatrain2(int n,vector<vector<int>>&points){
    vector<vector<int>>dp(n,vector<int>(4,-1));//4=3+1
    return f2(n-1,3,points,dp);
}


//TABULATION
//TC IS O(n*4*3) and SC IS O(n*4)
int ninjatrain3(int n,vector<vector<int>>&points){
    vector<vector<int>>dp(n,vector<int>(4,0));//4=3+1
    
    dp[0][0]=max(points[0][2],points[0][1]);
    dp[0][1]=max(points[0][2],points[0][0]);
    dp[0][2]=max(points[0][0],points[0][1]);
    dp[0][3]=max(points[0][2],max(points[0][1],points[0][0]));

    for(int day=1;day<n;day++){
        for(int last=0;last<4;last++){
            dp[day][last]=0;
            for(int task=0;task<3;task++){
                if(task!=last){
                    int point=points[day][task]+dp[day-1][task];
                    dp[day][last]=max(dp[day][last],point);
                }
            }
        }
    }
    return dp[n-1][3];
}

//Now we do Space Optimization
int ninjatrain4(int n,vector<vector<int>>&points){
    vector<int>prev(4,0);//4=3+1
    
    prev[0]=max(points[0][2],points[0][1]);
    prev[1]=max(points[0][2],points[0][0]);
    prev[2]=max(points[0][0],points[0][1]);to be the best for the versioned 
    prev[3]=max(points[0][2],max(points[0][1],points[0][0]));

    for(int day=1;day<n;day++){
        vector<int>temp(4,0);
        for(int last=0;last<4;last++){
            temp[last]=0;
            for(int task=0;task<3;task++){
                if(task!=last){
                    temp[last]=max(temp[last],points[day][task]+prev[task]);
                }
            }
        }
        prev=temp;
    }
    return prev[3];
}



int main(){
    int n=4;
    vector<vector<int>>points(n,vector<int>(3));
    cout<<"enter points: ";
    for(int i=0;i<4;i++){
        for(int j=0;j<3;j++){
            cin>>points[i][j];
        }
    }
    cout<<ninjatrain(n,points)<<endl;
    cout<<ninjatrain2(n,points)<<endl;
    cout<<ninjatrain3(n,points)<<endl;
    cout<<ninjatrain3(n,points)<<endl;
}