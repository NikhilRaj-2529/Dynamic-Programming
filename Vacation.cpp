#include<bits/stdc++.h>
using namespace std;
int dp[100001][4];
int solver(int ind,int n,vector<vector<int>> &arr,int prev){
    if(ind >= n) return 0;
    if(prev != -1 and dp[ind][prev] != -1) return dp[ind][prev];
    int maxi=0,p=0;
    for(int i=0;i<3;i++){
        if(i!=prev){
            p=arr[ind][i]+solver(ind+1,n,arr,i);
            maxi=max(p,maxi);
        }
    }
    if(prev!=-1) return dp[ind][prev]=max(maxi,p);
    return max(maxi,p);
}
int main(){
    int n;
    cin>>n;
    vector<vector<int>> arr(n,vector<int>(3));
    for(int i=0;i<n;i++){
        cin>>arr[i][0]>>arr[i][1]>>arr[i][2];
    }
    memset(dp,-1,sizeof(dp));
    cout<<solver(0,n,arr,-1);
}
