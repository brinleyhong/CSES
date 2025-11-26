#include <bits/stdc++.h>
using namespace std;
//O(NlogN^2)
#define sp " "
#define nl "\n"
const int maxn = 2e5;
int n, m, ans[maxn+5], h[maxn+5], room[maxn+5];
struct elm
{
    int val, idx; //maxval, index the element with the maximum value.
}seg[maxn*4+5];
void build(int id, int l, int r)
{
    if (l == r)
    {
        seg[id].val = h[l];
        seg[id].idx = l;
        return;
    }
    int mid = (l + r) / 2;
    build(id * 2, l, mid);
    build(id * 2 + 1, mid + 1, r);
    if (seg[id*2].val > seg[id*2+1].val)
    {
        seg[id].val = seg[id*2].val;
        seg[id].idx = seg[id*2].idx;
    }
    else
    {
        seg[id].val = seg[id*2+1].val;
        seg[id].idx = seg[id*2+1].idx;
    }
}
elm get(int id, int l, int r, int u, int v) //Get details of range [u, v]
{
    //l r u l r v l r
    if (r < u || v < l) return {-1, -1};
    if (u <= l && r <= v)
    {
        return seg[id];
    }
    int mid = (l + r) / 2;
    elm left = get(id*2, l, mid, u, v);
    elm right = get(id*2+1, mid+1, r, u, v);
    if (left.val > right.val) return left;
    else return right;
}
void update(int id, int l, int r, int point, int add)
{
    if (l == r) //reaches the leaf
    {
        seg[id].val += add; // point update
        seg[id].idx = l;
        return;
    }
    int mid = (l + r) / 2;
    if (point <= mid) update(id*2, l, mid, point, add);
    else update(id*2+1, mid+1, r, point, add);
    if (seg[id*2].val > seg[id*2+1].val)
    {
        seg[id].val = seg[id*2].val;
        seg[id].idx = seg[id*2].idx;
    }
    else
    {
        seg[id].val = seg[id*2+1].val;
        seg[id].idx = seg[id*2+1].idx;
    }
}
void solve()
{
    build(1, 1, n);
    for (int i = 1; i<=m; ++i)
    {
        int l = 1, r = n;
        //maxmimum of [1, i] <= maximum of [1, i+k] (k: a positive integer)
        int point = -1;
        //Do BS to get the left-most index with max(h[1], h[2], ... h[point]) >= r[i] p/s: update!
        while (l <= r)
        {
            int mid = (l + r) / 2;
            elm cur = get(1, 1, n, 1, mid);
            if (cur.val >= room[i]) //if the point were checking has maximum from h[1, mid] >= r[i] -> satisfied
            {
                r = mid - 1; //-> move the right bound to the left to get the "left-most index"
                point = mid; //this is an option for the answer, could be optimal or not
            }
            else
            {
                l = mid + 1; //not satisfied
            }
        }

        if (point == -1) { //if theres no such hotel with enough rooms for the current group
            ans[i] = 0;
            continue;
        }

        //if theres an available hotel with enough rooms for cur group
        //get the index of the chosen hotel
        elm chosen = get(1, 1, n, 1, point);
        ans[i] = chosen.idx;
        h[ans[i]]-=room[i];
        update(1, 1, n, ans[i], -room[i]); //Population of the current group from the chosen hotel
    }
}

int main() {

//    freopen("HOTELQUERIES.inp", "r", stdin);
//    freopen("HOTELQUERIES.out", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i<=n; ++i) cin >> h[i];
    for (int i = 1; i<=m; ++i) cin >> room[i];

    solve();

    for (int i = 1; i<=m; ++i) cout << ans[i] << sp;

    return 0;
}
