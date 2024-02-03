#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int solver(vector<pair<ll,ll>> &vt , ll ind , ll val, vector<vector<ll>> &dp){
  if(ind == vt.size()){
    if(val == 0) return val;
    return INT_MAX;
  }
  if(dp[ind][val] != -1) return dp[ind][val];
  ll a = solver(vt,ind+1,val,dp);
  if(vt[ind].second <= val){
    a = min(a,vt[ind].first+solver(vt,ind+1,val-vt[ind].second,dp));
  }
  return dp[ind][val] = a;
}
int main(){
  int n , k;
  cin >> n >> k;
  vector<pair<ll,ll>> vt;
  ll sum=0;
  for(int i = 0; i < n ; i++){
    int a , b;
    cin >> a >> b;
    vt.push_back({a,b});
    sum += b;
  }
  vector<vector<ll>> dp(n,vector<ll>(sum+1 , -1));
  for(ll i = sum ; i>=0 ; i--){
    ll ans = solver(vt,0,i,dp);
    if(ans <= k){
      cout << i <<"\n";
      break;
    }
  }
}
