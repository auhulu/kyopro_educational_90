// 一部WA,REとれず...多分考え方はおｋ
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (long long i = 0; i < (long long)(n); i++)
const long long MOD = 1000000007;
const long long INF = 1LL << 60;

// けんちょん式 Union-Find
struct UnionFind {
  vector<ll> par;

  UnionFind(ll n) : par(n, -1) {}

  ll root(ll x) {
    if (par[x] < 0)
      return x;
    else
      return par[x] = root(par[x]);
  }

  bool issame(ll x, ll y) { return root(x) == root(y); }

  bool merge(ll x, ll y) {
    x = root(x);
    y = root(y);
    if (x == y) return false;
    if (par[x] > par[y]) swap(x, y);
    par[x] += par[y];
    par[y] = x;
    return true;
  }

  ll size(ll x) { return -par[root(x)]; }
};

// 四方向への移動ベクトル
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int main() {
  ll h, w, q;
  cin >> h >> w >> q;
  vector<vector<ll>> F(h, vector<ll>(w));
  UnionFind UF(h * w);
  rep(i, q) {
    ll t;
    cin >> t;
    if (t == 1) {
      ll r, c;
      cin >> r >> c;
      r--;
      c--;
      F[r][c] = 1;
      rep(j, 4) {
        ll nr = r + dx[j];
        ll nc = c + dy[j];
        if (nr < 0 || nr >= h || nc < 0 || nc >= w) continue;
        if (F[nr][nc]) UF.merge(nr * h + nc, r * h + c);
      }
      continue;
    }
    ll ra, ca, rb, cb;
    cin >> ra >> ca >> rb >> cb;
    ra--;
    ca--;
    rb--;
    cb--;
    if (F[ra][ca] && F[rb][cb] && UF.issame(ra * h + ca, rb * h + cb))
      cout << "Yes" << endl;
    else
      cout << "No" << endl;
  }
}