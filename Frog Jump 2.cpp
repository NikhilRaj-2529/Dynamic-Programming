#include<bits/stdc++.h>
using namespace std;
int dp[100001];
int solver(vector<int> &vt,int n,int k,int ind){
  if(ind == n-1) return 0;
  if(dp[ind] != -1) return dp[ind];
  int a = INT_MAX;
  for(int i=1;i<=k;i++){
      if(ind + i <= n-1){
        a = min (a,abs(vt[ind]-vt[ind+i]) + solver(vt,n,k,ind+i));
      }
  }
  return dp[ind]=a;
}
int main(){
  int n,k;
  cin>>n>>k;
  vector<int>vt(n);
  for(int i=0;i<n;i++) cin>>vt[i];
  memset(dp,-1,sizeof(dp));
  cout<<solver(vt,n,k,0);
}
