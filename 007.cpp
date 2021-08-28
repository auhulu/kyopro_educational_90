#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (long long i = 0; i < (long long)(n); i++)
#define agewari(a, b) ((long long)a + ((long long)b - 1)) / b
const long long MOD = 1000000007;
const long long INF = 1LL << 60;

int main()
{
    ll n, q;
    cin >> n;
    vector<ll> A(n);
    rep(i, n) cin >> A[i];
    cin >> q;
    vector<ll> B(q);
    rep(i, q) cin >> B[i];
    sort(A.begin(), A.end());
    A.push_back(INF);
    A.insert(A.begin(), -INF);
    rep(i, q)
    {
        ll ng = A.size();
        ll ok = -1;
        while (abs(ok - ng) > 1)
        {
            ll mid = (ok + ng) / 2;
            if (A[mid] <= B[i])
                ok = mid;
            else
                ng = mid;
        }
        cout << min(abs(A[ok] - B[i]), abs(A[ng] - B[i])) << endl;
    }
}