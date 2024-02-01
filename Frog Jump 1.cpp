#include<bits/stdc++.h>
using namespace std;
int dp[100001];
int solver(vector<int> &vt,int n,int ind){
  if(ind == n-1) return 0;
  if(dp[ind] != -1) return dp[ind];
  int a = abs(vt[ind]-vt[ind+1]) + solver(vt,n,ind+1);
  int b = INT_MAX;
  if(ind+2<=n-1){
      b = abs(vt[ind]-vt[ind+2]) + solver(vt,n,ind+2);
  }
  return dp[ind] = min(a,b);
}
int main(){
  int n;
  cin>>n;
  vector<int>vt(n);
  for(int i=0;i<n;i++) cin>>vt[i];
  memset(dp,-1,sizeof(dp));
  cout<<solver(vt,n,0);
}
