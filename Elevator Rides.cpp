//[DP Bitmask, CSES] - Elevator Rides
//** Định nghĩa: Gọi dp[S].w là cân nặng của chuyến thang cuối cùng, dp[S].cnt là số chuyến tối thiểu để đưa những người trong tập S lên.
//** THCS: dp[0].w = 0, dp[0].cnt = 0
//** Đáp án: dp[2^n - 1].cnt
//** Công thức: S' không bao gồm người i
// 1) Đủ để nhét người thứ i vô chuyến thang máy cuối (dp[S'].w + w[i] <= x)
//      dp[S].w = dp[S].w + w[i], dp[S].cnt = dp[S].cnt
// 2) Không đủ để nhét người thú i vô chuyến thang máy cuối
//      dp[S].w = w[i],           dp[S].cnt = dp[S'].cnt + 1

#include <bits/stdc++.h>
using namespace std;
const int maxn = 20;
const int maxw = 1e9;
const int maxbit = 1<<maxn;
int w[maxn+5], n, x;
struct elm
{
    int cnt, weight;
}dp[ (1<<maxn) + 5];
void precomp()
{
    cin >> n >> x;
    for (int i = 0; i<n; ++i) cin >> w[i];
}
void solve()
{
    dp[0].cnt = 0, dp[0].weight = 0;
    for (int S = 1; S < (1<<n); ++S) {
        dp[S].cnt = n+1;
        dp[S].weight = x+1;

        for (int i = 0; i<n; ++i)
        {
            if (!(S & (1<<i))) continue;
            int S_ = S ^ (1<<i);
            int candidate_cnt, candidate_w;
            if (dp[S_].weight + w[i] <= x)
            {
                candidate_cnt = dp[S_].cnt;
                candidate_w = dp[S_].weight + w[i];
            }
            else
            {
                candidate_cnt = dp[S_].cnt + 1;
                candidate_w = w[i];
            }
            if (S_ == 0) candidate_cnt = 1;
            if (candidate_cnt < dp[S].cnt ||(candidate_cnt == dp[S].cnt && candidate_w < dp[S].weight))
            {
                dp[S].cnt = candidate_cnt;
                dp[S].weight = candidate_w;
            }
        }
    }
    cout << dp[(1<<n)-1].cnt;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    precomp();
    solve();
    return 0;
}
