#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int maxn = 1e5;
const int maxm = 100;
int n, m, a[maxn+5], dp[maxn+5][maxm+5]; //number of ways till i using j value
void solve()
{
    cin >> n >> m;
    for (int i = 1; i<=n; ++i) cin >> a[i];
    for (int i = 1; i<=n; ++i)
    {
        for (int j = 1; j<=m; ++j) dp[i][j] = 0;
    }
    if (a[1] == 0) {
        for (int i = 1; i<=m; ++i)
            dp[1][i] = 1;
    }
    else dp[1][a[1]] = 1;
    for (int i = 2; i<=n; ++i)
    {
        if (a[i] != 0) {
            dp[i][a[i]] = (dp[i][a[i]]%mod + dp[i-1][a[i]]%mod)%mod;
            dp[i][a[i]] = (dp[i][a[i]]%mod + dp[i-1][a[i]-1]%mod)%mod;
            if (a[i] < m) dp[i][a[i]] = (dp[i][a[i]]%mod + dp[i-1][a[i]+1]%mod)%mod;
        }
        else
        {
            for (int j = 1; j<=m; ++j)
            {
                dp[i][j] = (dp[i][j]%mod + dp[i-1][j-1]%mod)%mod;
                dp[i][j] = (dp[i][j]%mod + dp[i-1][j]%mod)%mod;
                if (j + 1 <= m) dp[i][j] = (dp[i][j]%mod +  dp[i-1][j+1]%mod)%mod;
            }
        }
    }
    int ans = 0;
    for (int i = 1; i<=m; ++i)
    {
        ans = (ans % mod + dp[n][i]%mod)%mod;
    }
    cout << ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
