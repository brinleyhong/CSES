#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3;
int n, m;
char a[maxn+5][maxn+5];
bool vis[maxn+5][maxn+5];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
bool valid(int x, int y)
{
    return ((x>=1 && y>=1 && x<=n && y<=m) && (!vis[x][y]));
}
void dfs(int x, int y)
{
    vis[x][y] = true;
    for (int k = 0; k<4; ++k)
    {
        int nx = x + dx[k];
        int ny = y + dy[k];
        if (valid(nx, ny)) dfs(nx, ny);
    }
}
void solve()
{
    int cnt = 0;
    for (int i = 1; i<=n; ++i)
    {
        for (int j = 1; j<=m; ++j)
        {
            if (!vis[i][j]) {
                dfs(i, j);
                ++cnt;
            }
        }
    }
    cout << cnt;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i<=n; ++i)
    {
        for (int j = 1; j<=m; ++j) {
            cin >> a[i][j];
            if (a[i][j] == '#') vis[i][j] = true;
        }
    }
    solve();
    return 0;
}
