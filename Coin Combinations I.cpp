#include <bits/stdc++.h>
using namespace std;
const int maxn = 100;
const int maxx = 1e6;
const int mod = 1e9 + 7;
int n, x, a[maxn+5], dp[maxx+5];
void input()
{
    cin >> n >> x;
    for (int i = 1; i<=n; ++i) cin >> a[i];
}
void basecase()
{
    for (int i = 1; i<=x; ++i) dp[i] = 0;
    for (int i= 1; i<=n; ++i) dp[a[i]] = 1;
}
void solve()
{
    basecase();
    for (int sum = 0; sum <= x; ++sum)
    {
        for (int idx = 1; idx <= n; ++idx) ///
        {
            int v = a[idx];
            if (sum - v < 0) continue;
            dp[sum] = (dp[sum] + dp[sum-v]) % mod;
            //cout << "sum: " << sum << "  idx: " << idx << "  a[idx]: " << a[idx] << "  dp[sum+v]: " << dp[sum+v] << "  dp[sum]: " << dp[sum] << "  dp[v]: " << dp[v] << "\n";
        }
    }
//    for (int sum = 0; sum <= x; ++sum)
//        cout << "sum: " << sum << " dp[sum]: " << dp[sum] << "\n";
    cout << dp[x];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
//    freopen("Coin Combinations I.inp", "r", stdin);
//    froepen("Coin Combinations I.out", "w", stdout);
    input();
    solve();
    return 0;
}
