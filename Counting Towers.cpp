#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6;
const int mod = 1e9 + 7;
int dp[maxn+2][2]; //width 1 - width 2
void process()
{
    dp[1][1] = 1;
    dp[1][0] = 1;
    for (int i = 2; i<=maxn; ++i)
    {
        dp[i][0] = (4LL * dp[i-1][0] + dp[i-1][1])%mod;
        dp[i][1] = (2LL *dp[i-1][1] + dp[i-1][0])%mod;
    }
}
void solve()
{
    int t; cin >> t;
    while (t--)
    {
        int x; cin >> x;
        cout << (dp[x][1]+ dp[x][0])%mod << "\n";
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    process();
    solve();
    return 0;
}
