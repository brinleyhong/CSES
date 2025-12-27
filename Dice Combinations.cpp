#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6;
const int mod = 1e9 + 7;
int dp[maxn+5], n;
void solve()
{
    cin >> n;
    dp[0] = 1;
    for (int sum = 1; sum <= n; ++sum)
    {
        for (int idx = 1; idx <= 6; ++idx)
        {
            if (idx > sum) break;
            dp[sum] = (dp[sum]%mod + dp[sum-idx]%mod)%mod;
        }
    }
    cout << dp[n];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    //freopen("Dice Combinations.inp", "r", stdin);
    //freopen("Dice Combinations.out", "w", stdout;
    solve();
    return 0;
}
