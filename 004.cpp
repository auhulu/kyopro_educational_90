#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (long long i = 0; i < (long long)(n); i++)
#define agewari(a, b) ((long long)a + ((long long)b - 1)) / b
const long long MOD = 1000000007;
const long long INF = 1LL << 60;
int main()
{
    ll h, w;
    cin >> h >> w;
    ll A[h][w];
    rep(i, h)
    {
        rep(j, w) cin >> A[i][j];
    }

    ll sum_yoko[h];
    ll sum_tate[w];
    rep(i, h)
    {
        ll sum = 0;
        rep(j, w) sum += A[i][j];
        sum_yoko[i] = sum;
    }
    rep(j, w)
    {
        ll sum = 0;
        rep(i, h) sum += A[i][j];
        sum_tate[j] = sum;
    }

    rep(i, h)
    {
        rep(j, w) cout << sum_yoko[i] + sum_tate[j] - A[i][j] << " ";
        cout << endl;
    }
}