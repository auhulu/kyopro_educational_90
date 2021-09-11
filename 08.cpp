#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (long long i = 0; i < (long long)(n); i++)
#define agewari(a, b) ((long long)a + ((long long)b - 1)) / b
const long long MOD = 1000000007;
const long long INF = 1LL << 60;
int main() {
  ll n;
  string s;
  cin >> n >> s;
  s = "@" + s;
  string t = "@atcoder";
  vector<vector<ll>> dp(n + 1, vector<ll>(8));  //テーブル(番兵分の追加)
  dp[0][0] = 1;
  rep(i, n) {
    rep(j, 8) {
      (dp[i + 1][j] += dp[i][j]) %= MOD;
      if (j < 7 && t[j + 1] == s[i + 1]) dp[i + 1][j + 1] = dp[i][j];
    }
  }

  // for(auto col:dp){
  //   for(auto value:col){
  //     cout<<value<<" ";
  //   }
  //   cout<<endl;
  // }
  cout << dp[n][7] << endl;
}