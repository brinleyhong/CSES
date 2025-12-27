#include <bits/stdc++.h>
using namespace std;
const int maxn = 100;
const int maxx = 1e6;
int n, x, a[maxn+5], dp[maxx+5];
void input()
{
    cin >> n >> x;
    for (int i = 1; i<=n; ++i) cin >> a[i];
}
void basecase()
{
    for (int i = 1; i<=x; ++i) dp[i] = INT_MAX;
    for (int i = 1; i<=n; ++i) dp[a[i]] = 1;
}
void solve()
{
    basecase();
    for (int sum = 1; sum<=x; ++sum)
    {
        for (int idx = 1; idx<=sum; ++idx)
        {
            int v = a[idx];
            dp[sum + v] = min(dp[sum + v], dp[sum]+1);
        }
    }
    if (dp[x] == INT_MAX) dp[x] = -1;
    cout << dp[x];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    input();
    solve();
    return 0;
}
