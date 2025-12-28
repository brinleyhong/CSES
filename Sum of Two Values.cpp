#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5;
int n, x, sorted_val[maxn+5], sorted_id[maxn+5];
struct elm
{
    int val, id;
}a[maxn+5];
bool cmp(elm x, elm y)
{
    return x.val < y.val;
}
void solve()
{
    cin >> n >> x;
    for (int i = 1; i<=n; ++i) {
        cin >> a[i].val;
        a[i].id = i;
    }
    sort(a+1, a+n+1, cmp);
    for (int i = 1; i<=n; ++i)
    {
        sorted_val[i] = a[i].val;
        sorted_id[i] = a[i].id;
    }
    bool flag = false;
    for (int i = 1; i<=n; ++i)
    {
        if (a[i].val > x / 2) break;
        int need_val = x - a[i].val;
        int left_bound = lower_bound(sorted_val+1, sorted_val+n+1, need_val) - sorted_val;
        if (sorted_val[left_bound] != need_val) continue;
        int right_bound = upper_bound(sorted_val+1, sorted_val+n+1, need_val) - sorted_val - 1;
        for (int j = left_bound; j <= right_bound; ++j)
        {
            if (need_val == sorted_val[i] && sorted_id[i] >= sorted_id[j]) continue;
            cout << sorted_id[i] << " " << sorted_id[j] << "\n";
            return;
        }
     }
    cout << "IMPOSSIBLE";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
