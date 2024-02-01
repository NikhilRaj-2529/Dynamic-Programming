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

// Second Approah

#include<bits/stdc++.h>
using namespace std;
int dp[100001][4];
int points(int ind,int col,int n,int c,vector<vector<int>>& arr){
    if(ind==n) return c;
    if(dp[ind][col]!=-1) return dp[ind][col];
    int ans=INT_MIN;
    if(ind==0){
        ans=max(ans,c+points(1,0,n,arr[0][0],arr));
        ans=max(ans,c+points(1,1,n,arr[0][1],arr));
        ans=max(ans,c+points(1,2,n,arr[0][2],arr));
    }
    else{
        if(col!=0) ans=max(ans,c+points(ind+1,0,n,arr[ind][0],arr));
        if(col!=1) ans=max(ans,c+points(ind+1,1,n,arr[ind][1],arr));
        if(col!=2) ans=max(ans,c+points(ind+1,2,n,arr[ind][2],arr));
        
    }
    return dp[ind][col]=ans;
}
int main(){
  int n;
  cin>>n;
  vector<vector<int>> arr;
  for(int i=0;i<n;i++){
      vector<int> v(3);
      for(int j=0;j<3;j++) cin>>v[j];
      arr.push_back(v);
      v.clear();
  }
  memset(dp,-1,sizeof(dp));
  cout<<points(0,0,n,0,arr);
}
