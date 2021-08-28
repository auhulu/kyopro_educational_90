#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (long long i = 0; i < (long long)(n); i++)
#define agewari(a, b) ((long long)a + ((long long)b - 1)) / b
const long long MOD = 1000000007;
const long long INF = 1LL << 60;

// 2回BFS、書き方は冗長だがわかりやすさ優先で
int main() {
  ll n;
  cin >> n;
  vector<vector<ll>> G(n);
  rep(i, n - 1) {
    ll a, b;
    cin >> a >> b;
    a--;
    b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }

  // BFS のためのデータ構造
  vector<ll> dist(n, -1);  // 全頂点を「未訪問」に初期化
  queue<ll> que;
  // 初期条件 (頂点 0 を初期ノードとする)
  dist[0] = 0;
  que.push(0);  // 0 を橙色頂点にする
  // BFS 開始 (キューが空になるまで探索を行う)
  while (!que.empty()) {
    ll v = que.front();  // キューから先頭頂点を取り出す
    que.pop();

    // v から辿れる頂点をすべて調べる
    for (ll nv : G[v]) {
      if (dist[nv] != -1) continue;  // すでに発見済みの頂点は探索しない

      // 新たな白色頂点 nv について距離情報を更新してキューに追加する
      dist[nv] = dist[v] + 1;
      que.push(nv);
    }
  }

  ll farthest_v = 0;
  ll max_dist = 0;
  rep(i, n) {
    if (dist[i] > max_dist) {
      max_dist = dist[i];
      farthest_v = i;
    }
  }

  // BFS のためのデータ構造
  rep(i, n) dist[i] = -1;
  // 初期条件 (頂点 0 を初期ノードとする)
  dist[farthest_v] = 0;
  que.push(farthest_v);  // 0 を橙色頂点にする
  // BFS 開始 (キューが空になるまで探索を行う)
  while (!que.empty()) {
    ll v = que.front();  // キューから先頭頂点を取り出す
    que.pop();

    // v から辿れる頂点をすべて調べる
    for (ll nv : G[v]) {
      if (dist[nv] != -1) continue;  // すでに発見済みの頂点は探索しない

      // 新たな白色頂点 nv について距離情報を更新してキューに追加する
      dist[nv] = dist[v] + 1;
      que.push(nv);
    }
  }

  rep(i, n) {
    if (dist[i] > max_dist) max_dist = dist[i];
  }
  cout << max_dist + 1 << endl;
}