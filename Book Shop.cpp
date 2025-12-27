#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000;
const int maxx = 1e5;
int n, x, pr[maxn+1], p[maxn+1], dp[maxx+1][maxn+1];
void input()
{
    cin >> n >> x;
    for (int i = 1; i<=n; ++i) cin >> pr[i]; //price
    for (int i = 1; i<=n; ++i) cin >> p[i]; //pages
}
void solve()
{
    for (int i = 1; i<=n; ++i)
    {
        for (int sum = 1; sum <= x; ++sum)
        {
            dp[sum][i] = dp[sum][i-1];
            if (sum - pr[i] < 0) continue;
            dp[sum][i] = max(dp[sum][i], dp[sum-pr[i]][i-1] + p[i]);
        }
    }
    cout << dp[x][n];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    input();
    solve();

    return 0;
}
