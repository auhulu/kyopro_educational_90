#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (long long i = 0; i < (long long)(n); i++)
#define agewari(a, b) ((long long)a + ((long long)b - 1)) / b
const long long MOD = 1000000007;
const long long INF = 1LL << 60;

bool isOk(string s)
{
    ll cnt = 0;
    rep(i, s.length())
    {
        if (s[i] == '(')
            cnt++;
        else
            cnt--;
        if (cnt < 0)
            return false;
    }
    if (cnt == 0)
        return true;
    else
        return false;
}
int main()
{
    ll n;
    cin >> n;
    // bit全探索で全列挙
    set<string> ans;
    for (ll i = 0; i < (1 << n); i++)
    {
        string s = "";
        rep(j, n)
        {
            if (i & (1 << j))
                s += "(";
            else
                s += ")";
        }
        if (isOk(s))
            ans.insert(s);
    }
    for (auto s : ans)
        cout << s << endl;
}