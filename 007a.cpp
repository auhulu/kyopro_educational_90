// O(N)の別解(WAとれず...)
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
    vector<pair<ll, ll>> B(q);
    rep(i, q)
    {
        ll b;
        cin >> b;
        B[i].first = b;
        B[i].second = i;
    }

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    vector<ll> ans(q);
    ll j = -1;
    rep(i, q)
    {
        ll dif = INF;
        while (1)
        {
            if (j == n)
            {
                ans[B[i].second] = dif;
                break;
            }
            else if (dif > abs(B[i].first - A[j]))
            {
                j++;
                dif = abs(B[i].first - A[j]);
            }
            else
            {
                ans[B[i].second] = dif;
                j--;
                break;
            }
        }
    }
    rep(i,q)cout<<ans[i]<<endl;
}