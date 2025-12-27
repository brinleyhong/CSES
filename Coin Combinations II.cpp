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
    for (int i = 0; i<=x; ++i) dp[i] = 0;
    dp[0] = 1;
}
void solve()
{
    basecase();
    for (int idx = 1; idx <= n; ++idx)
    {
        for (int sum = 1; sum <= x; ++sum)
        {
            int v = a[idx];
            if (v > sum) continue;
            dp[sum] = (dp[sum]%mod +  dp[sum-v]%mod)%mod;
        }
    }
    cout << dp[x]%mod;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    input();
    solve();
    return 0;
}
