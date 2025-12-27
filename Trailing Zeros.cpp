#include <bits/stdc++.h>
using namespace std;
int d(int n)
{
    if (n == 0) return 0;
    return n/5 + d(n/5);
}
void solve()
{
    int n; cin >> n;
    int ans = d(n);
    cout << ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
