#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (long long i = 0; i < (long long)(n); i++)
#define agewari(a, b) ((long long)a + ((long long)b - 1)) / b
const long long MOD = 1000000007;
const long long INF = 1LL << 60;
int main()
{
    ll n, k;
    string s;
    cin >> n >> k >> s;

    // 貪欲の前計算
    vector<vector<ll>> C(n, vector<ll>(26));
    rep(i, n)
    {
        rep(j, 26) C[i][j] = INF;
    }
    for (ll i = n - 1; i >= 0; i--)
    {
        ll j = s[i] - 97;
        if (i != n - 1)
            C[i] = C[i + 1];
        C[i][j] = i;
    }

    ll cnt = 0; //何文字目まで決まったかカウント
    string ans = "";
    rep(i, n)
    {
        rep(j, 26)
        {
            if (n - C[i][j] >k - cnt - 1)
            {
                ans += char(j + 97);
                cnt++;
                if (cnt == k)
                {
                    cout << ans << endl;
                    return 0;
                }
                i = C[i][j];
                break;
            }
        }
    }
}