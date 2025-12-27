#include <bits/stdc++.h>
using namespace std;
#define int long long
int solve(int x, int y)
{
    int m = max(x, y);
    int sqrt = (m-1)*(m-1);
    int ans;
    if (m%2==1)
        ans = sqrt+y+m-x;
    else ans = sqrt+x+m-y;
    return ans;
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--) {
        int x, y; cin >> x >> y;
        cout << solve(x, y) << "\n";
    }
    return 0;
}
