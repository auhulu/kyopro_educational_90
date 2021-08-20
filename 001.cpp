#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (long long i = 0; i < (long long)(n); i++)
#define agewari(a, b) ((long long)a + ((long long)b - 1)) / b
const long long MOD = 1000000007;
const long long INF = 1LL << 60;

bool isOk(vector<ll> A, ll l, ll k, ll m)
{
    ll last = 0, cnt = 0;
    rep(i, A.size())
    {
        if (A[i] - last >= m)
        {
            last = A[i];
            cnt++;
            if (cnt == k)
            {
                if (l - last >= m)
                    return true;
                else
                    return false;
            }
        }
    }
    return false;
}

int main()
{
    ll n, l, k;
    cin >> n >> l >> k;
    vector<ll> A(n);
    rep(i, n) cin >> A[i];
    // isOkを使ったにぶたん
    ll ng = l;
    ll ok = 0;
    while (abs(ok - ng) > 1)
    {
        ll mid = (ok + ng) / 2;
        if (isOk(A, l, k, mid))
            ok = mid;
        else
            ng = mid;
    }
    cout << ok << endl;
}