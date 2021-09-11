#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (long long i = 0; i < (long long)(n); i++)
const long long MOD = 1000000007;
const long long INF = 1LL << 60;
int main() {
  ll n;
  cin >> n;
  vector<ll> A(n), B(n);
  rep(i, n) {
    ll c, p;
    cin >> c >> p;
    if (i == 0) {
      if (c == 1)
        A[i] = p;
      else
        B[i] = p;
      continue;
    }
    if (c == 1) {
      A[i] = A[i - 1] + p;
      B[i] = B[i - 1];
    } else {
      B[i] = B[i - 1] + p;
      A[i] = A[i - 1];
    }
  }
  ll q;
  cin >> q;
  rep(i, q) {
    ll l, r;
    cin >> l >> r;
    l--;
    r--;
    if (l == 0)
      cout << A[r] << " " << B[r] << endl;
    else
      cout << A[r] - A[l - 1] << " " << B[r] - B[l - 1] << endl;
  }
}