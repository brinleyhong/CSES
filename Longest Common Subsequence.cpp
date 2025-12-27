#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3;
int dp[maxn+5][maxn+5], a[maxn+5], b[maxn+5], n, m;
pair <int, int> trace[maxn+5][maxn+5];
int val[maxn+5][maxn+5];
void solve()
{
    for (int i = 1; i<=n; ++i)
    {
        for (int j = 1; j<=m; ++j)
        {
            val[i][j] = 0;
            if (dp[i-1][j] > dp[i][j-1])
            {
                trace[i][j] = {i-1, j};
            }
            else trace[i][j] = {i, j-1};
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            if (a[i] == b[j])
            {
                if (dp[i-1][j-1] + 1 > dp[i][j]) {
                    trace[i][j] = make_pair(i-1, j-1);
                    val[i][j] = a[i];
                }
                dp[i][j] = max(dp[i][j], dp[i-1][j-1] + 1);
            }
        }
    }
    vector <int> ans;
    int curx = n, cury = m;
    while (dp[curx][cury]!=0)
    {
        if (val[curx][cury] != 0) ans.push_back(val[curx][cury]);
        int u = trace[curx][cury].first;
        int v = trace[curx][cury].second;
        curx = u, cury = v;
    }
    reverse(ans.begin(), ans.end());
    cout << dp[n][m] << "\n";
    for (int v : ans) cout << v << " ";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i =1; i<=n; ++i) cin >> a[i];
    for (int i = 1; i<=m; ++i) cin >> b[i];
    solve();
    return 0;
}
