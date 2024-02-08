#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int dp[20][100][2];
vector<int> nums;
ll a, b, c, d;
ll solver(ll pos, ll cnt , ll flag){
    if(cnt > d) return 0;
    if(pos >= nums.size()){
        if(cnt == d) return 1;
        return 0;
    }
    if(dp[pos][cnt][flag] != -1)  return dp[pos][cnt][flag];
    ll lim , ans = 0;
    if(flag == 1) lim = 9;
    else lim = nums[pos];
    for(int i = 0 ; i <= lim ; i++){
        ll nflag = flag;
        ll ncnt = cnt;
        if(flag == 0 and i < lim) nflag = 1;
        if(i == c) ncnt++;
        if(ncnt <= d) ans += solver(pos+1 , ncnt , nflag);
    }
    return dp[pos][cnt][flag] = ans;
}
ll solve(ll b){
    nums.clear();
    while(b!=0){
        nums.push_back(b%10);
        b = b/10;
    }
    reverse(nums.begin(),nums.end());
    memset(dp,-1,sizeof(dp));
    int ans = solver(0, 0, 0);
    return ans;
}
int main() {
	cin >> a >> b >> c >> d;
	ll ans = solve(b) - solve(a - 1);
	cout << ans;
}
